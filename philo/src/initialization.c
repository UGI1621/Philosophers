/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:25:55 by saan              #+#    #+#             */
/*   Updated: 2025/05/24 17:19:45 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_obs(t_obs *obs, int pn, int ac, char *av[])
{
	int i;

	obs->head = NULL;
	obs->tid = 0;
	obs->ph_n = pn;
	obs->met = -1;
	if (av[5])
		obs->met = ft_atoi(av[5]);
	pthread_mutex_init(&obs->m_et, NULL);
	obs->ml_printf = 0;
	obs->tail = NULL;
	obs->is_lock = (int *)ft_calloc(pn, sizeof(int));
	obs->forks = (pthread_mutex_t *)ft_calloc(pn, sizeof(pthread_mutex_t));
	pthread_mutex_init(&obs->m_printf, NULL);
	pthread_mutex_init(&obs->m_amid, NULL);

	return (0);
}

static t_philo	*make_philo_node(t_obs *obs, int i, char *av[], struct timeval ct)
{
	t_philo *cur;

	cur = (t_philo *)ft_calloc(1, sizeof(t_philo));
	cur->tid = 0;
	cur->s_time = ct;
	cur->m_printf = &obs->m_printf;
	cur->ml_pinrtf = &obs->ml_printf;
	cur->amid = 0;
	cur->m_amid = &obs->m_amid;
	cur->pn = i + 1;
	cur->ttd = ft_atoi(av[2]);
	cur->init_ttd = cur->ttd;
	cur->tte = ft_atoi(av[3]);
	cur->tts = ft_atoi(av[4]);
	cur->m_et = &obs->m_et;
	cur->l_f = &obs->forks[i];
	cur->r_f = &obs->forks[(i - 1 + ft_atoi(av[1])) % ft_atoi(av[1])];
	cur->ll_f = 0;
	cur->lr_f = 0;
	cur->et = 0;
	cur->met = -1;
	if (av[5])
		cur->met = ft_atoi(av[5]);
	return (cur);
}

int	init_cdll(t_obs *obs, char *av[], struct timeval ct)
{
	t_philo	*node;
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		node = make_philo_node(obs, i, av, ct);
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
