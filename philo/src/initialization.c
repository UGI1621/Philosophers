/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:25:55 by saan              #+#    #+#             */
/*   Updated: 2025/04/30 10:21:23 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_obs(t_obs *obs, int pn)
{
	int i;

	obs->head = NULL;
	obs->tid = 0;
	obs->is_dead = 0;
	obs->is_met = -1;
	obs->tail = NULL;
	obs->is_lock = (int *)ft_calloc(pn, sizeof(int));
	if (!obs->is_lock)
		return (1);
	obs->forks = (pthread_mutex_t *)ft_calloc(pn, sizeof(pthread_mutex_t));
	i = -1;
	while (++i < pn)
	{
		if (pthread_mutex_init(&obs->forks[i], NULL) != 0)
		{
			perror("fail init mutex");
			destroy_all_mutex(obs->forks, i - 1);
			return (1);
		}
	}
	return (0);
}

static t_philo	*make_philo_node(t_obs *obs, int i, char *av[])
{
	t_philo *cur;

	cur = (t_philo *)calloc(1, sizeof(t_philo));
	if (!cur)
		return (NULL);
	cur->tid = 0;
	cur->amid = 0;
	cur->pn = i + 1;
	cur->ttd = ft_atoi(av[2]);
	cur->init_ttd = cur->ttd;
	cur->tte = ft_atoi(av[3]);
	cur->tts = ft_atoi(av[4]);
	cur->l_f = &obs->forks[i];
	cur->r_f = &obs->forks[(i - 1 + ft_atoi(av[1])) % ft_atoi(av[1])];
	cur->ll_f = &obs->is_lock[i];
	cur->lr_f = &obs->is_lock[(i - 1 + ft_atoi(av[1])) % ft_atoi(av[1])];
	if (av[5])
		cur->met = ft_atoi(av[5]);
	return (cur);
}

int	init_cdll(t_obs *obs, char *av[])
{
	t_philo	*node;
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		node = make_philo_node(obs, i, av);
		if (!node)
			return (e_w_f("fmpn", obs, i));
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
	obs->tail->next = obs->head;
	obs->head->prev = obs->tail;
	return (0);
}
