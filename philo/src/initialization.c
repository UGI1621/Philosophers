/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:25:55 by saan              #+#    #+#             */
/*   Updated: 2025/04/27 11:21:46 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_obs(t_obs *obs)
{
	obs->head = NULL;
	obs->is_dead = 0;
	obs->is_met = -1;
	obs->tail = NULL;
}

static t_philo	*make_philo_node(int i, char *av[])
{
	t_philo *cur;

	cur = ft_calloc(1, sizeof(t_philo));
	if (!cur)
		return (NULL);
	cur->pn = i;
	cur->ttd = ft_atoi(av[2]);
	cur->tte = ft_atoi(av[3]);
	cur->tts = ft_atoi(av[4]);
	if (av[5])
		cur->met = ft_atoi(av[5]);
	return (cur);
}

void	init_cdll(t_obs *obs, char *av[])
{
	t_philo	*node;
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		node = make_philo_node(i, av);
		if (!obs->head)
		{
			obs->head = node;
			obs->tail = node;
		}
		else
		{
			obs->tail->next = node;
			node->prev = obs->tail;
			obs->tail = node;
		}
	}
}
