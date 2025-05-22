/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:25:55 by saan              #+#    #+#             */
/*   Updated: 2025/05/22 16:17:00 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_obs(t_obs *obs, int pn, int ac, char *av[])
{
	int i;

	obs->head = NULL;
	obs->tid = 0;
	obs->ph_n = pn;
	// obs->init_met = -1;
	// if (ac == 6)
	// 	obs->init_met = ft_atoi(av[5]);
	// obs->pet = 0;
	pthread_mutex_init(&obs->m_et, NULL);
	obs->tail = NULL;
	obs->is_lock = (int *)ft_calloc(pn, sizeof(int));
	obs->forks = (pthread_mutex_t *)ft_calloc(pn, sizeof(pthread_mutex_t));
	pthread_mutex_init(&obs->m_printf, NULL);
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

static t_philo	*make_philo_node(t_obs *obs, int i, char *av[], struct timeval ct)
{
	t_philo *cur;

	cur = (t_philo *)ft_calloc(1, sizeof(t_philo));
	cur->tid = 0;
	cur->s_time = ct;
	cur->m_printf = &obs->m_printf;
	cur->amid = 0;
	cur->pn = i + 1;
	cur->ttd = ft_atoi(av[2]);
	cur->init_ttd = cur->ttd;
	cur->tte = ft_atoi(av[3]);
	cur->tts = ft_atoi(av[4]);
	// cur->e_flag = 0;
	cur->m_et = &obs->m_et;
	cur->l_f = &obs->forks[i];
	cur->r_f = &obs->forks[(i - 1 + ft_atoi(av[1])) % ft_atoi(av[1])];
	// cur->ll_f = &obs->is_lock[i];
	// cur->lr_f = &obs->is_lock[(i - 1 + ft_atoi(av[1])) % ft_atoi(av[1])];
	cur->ll_f = 0;
	cur->lr_f = 0;
	cur->et = 0;
	if (av[5])
		cur->met = ft_atoi(av[5]);
	else
		cur->met = -1;
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
