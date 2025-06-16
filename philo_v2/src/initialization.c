/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 08:25:55 by saan              #+#    #+#             */
/*   Updated: 2025/06/16 19:05:02 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex_forks(t_fork *forks, int pn)
{
	int	i;

	i = -1;
	while (++i < pn)
	{
		pthread_mutex_init(&forks[i].box, NULL);
		forks[i].status = 1;
	}
	return (0);
}

int	init_obs(t_obs *obs, int pn, char *av[])
{
	pthread_mutex_init(&obs->ready.box, NULL);
	obs->ready.ready = 0;
	obs->head = NULL;
	obs->tid = 0;
	obs->ph_n = pn;
	obs->met = -1;
	if (av[5])
		obs->met = ft_atoi(av[5]);
	obs->l_print = 0;
	obs->tail = NULL;
	obs->forks = (t_fork *)ft_calloc(pn, sizeof(t_fork));
	init_mutex_forks(obs->forks, pn);
	pthread_mutex_init(&obs->m_print, NULL);
	pthread_mutex_init(&obs->m_stat, NULL);
	return (0);
}

static t_philo	*make_philo_node(t_obs *obs, int i, char *av[],
		struct timeval ct)
{
	t_philo	*cur;

	cur = (t_philo *)ft_calloc(1, sizeof(t_philo));
	cur->ready = &obs->ready;
	cur->prev = NULL;
	cur->tid = 0;
	cur->pn = i + 1;
	cur->ttd = ft_atoi(av[2]);
	cur->init_ttd = cur->ttd;
	cur->tte = ft_atoi(av[3]);
	cur->tts = ft_atoi(av[4]);
	cur->rh = 0;
	cur->lh = 0;
	cur->lb = &obs->forks[i];
	cur->rb = &obs->forks[(i - 1 + ft_atoi(av[1])) % ft_atoi(av[1])];
	cur->status.box = &obs->m_stat;
	cur->status.et = 0;
	cur->status.d = 0;
	cur->print.l_print = &obs->l_print;
	cur->print.box = &obs->m_print;
	cur->s_time = ct;
	cur->next = NULL;
	return (cur);
}

int	init_cdll(t_obs *obs, char *av[], struct timeval ct)
{
	t_philo	*node;
	int		i;

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
