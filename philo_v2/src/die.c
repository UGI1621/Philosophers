/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:37:41 by saan              #+#    #+#             */
/*   Updated: 2025/05/27 18:58:34 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_died(t_philo *p)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(p->status.box);
	if (p->status.d)
		flag = 1;
	pthread_mutex_unlock(p->status.box);
	return (flag);
}

void	set_died(t_philo *p)
{
	pthread_mutex_lock(p->status.box);
	p->status.d = 1;
	pthread_mutex_unlock(p->status.box);
}

static void	set_all_died(t_obs *obs)
{
	int	i;
	t_philo *p;

	i = -1;
	p = obs->head;
	while (++i < obs->ph_n)
	{
		p->status.d = 1;
		p = p->next;
	}
}

static int	obs_check_died(t_obs *obs)
{
	int	flag;
	int	i;
	t_philo *p;

	flag = 0;
	i = -1;
	p = obs->head;
	pthread_mutex_lock(&obs->m_stat);
	while (++i < obs->ph_n)
	{
		if (p->status.d)
		{
			flag = 1;
			set_all_died(obs);
		}
		p = p->next;
	}
	pthread_mutex_unlock(&obs->m_stat);
	return (flag);
}

int	find_dead_p(t_obs *obs)
{
	int	i;
	t_philo *p;

	i = -1;
	p = obs->head;
	if (obs_check_died(obs))
		return (1);
	return (0);
}
