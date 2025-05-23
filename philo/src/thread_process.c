/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:33:29 by saan              #+#    #+#             */
/*   Updated: 2025/05/23 19:46:30 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die_from_ttd(t_obs *obs, t_philo *cur)
{
	int	i;
	struct timeval	ct;
	i = -1;
	while (1)
	{
		gettimeofday(&ct, NULL);
		if (pthread_mutex_lock(cur->m_printf) == 0)
		{
			printf("%ld %d died\n", cal_ct(cur->s_time, ct), cur->pn);
			obs->ml_printf = 1;
			pthread_mutex_unlock(cur->m_printf);
			break ;
		}
		else
			continue ;
	}
	while (++i < obs->ph_n)
	{
		cur = cur->next;
		cur->amid = 1;
	}
}

int	count_et(t_obs *obs, t_philo *p)
{
	int	i;
	int	done;
	t_philo *cur;

	i = -1;
	done = 1;
	cur = obs->head;
	while (++i < obs->ph_n)
	{
		if (!(cur->et >= obs->met))
			done = 0;
		cur = cur->next;
	}
	if (done)
	{
		i = -1;
		while (++i < obs->ph_n)
		{
			cur->amid = 1;
			cur = cur->next;
		}
		return (1);
	}
	return (0);
}

void	*obs_routine(void *obs_unit)
{
	t_obs *obs;
	t_philo *cur;

	obs = (t_obs *)obs_unit;
	cur = obs->head;
	while(1)
	{
		if (cur->amid)
		{
			die_from_ttd(obs, cur);
			return (NULL);
		}
		if (obs->met != -1 && count_et(obs, cur))
		return (NULL);
		cur = cur->next;
	}
	return (NULL);
}

void	*routine(void *cur)
{
	t_philo *p;
	struct timeval ct;

	p = (t_philo *)cur;
	while (1)
	{
		gettimeofday(&ct, NULL);
		update_ttd(p, ct);
		if (p->amid)
			return (NULL);
		if (thinking(p) == -1)
			return (NULL);
		eating(p);
		sleeping(p);
	}
	return (NULL);
}

void	thread_process(t_obs *obs, int pn)
{
	create_all_pthread(obs, pn);
	join_all_pthread(obs, pn);
}
