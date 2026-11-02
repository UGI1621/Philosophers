/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:33:29 by saan              #+#    #+#             */
/*   Updated: 2025/06/16 19:04:30 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_ready(t_ready *ready)
{
	pthread_mutex_lock(&ready->box);
	if (ready->ready)
	{
		pthread_mutex_unlock(&ready->box);
		return (1);
	}
	pthread_mutex_unlock(&ready->box);
	return (0);
}

void	*obs_routine(void *obs_unit)
{
	t_obs	*obs;

	obs = (t_obs *)obs_unit;
	while (1)
	{
		if (check_ready(&obs->ready))
			break ;
	}
	while (1)
	{
		if (check_end(obs))
			return (NULL);
	}
}

void	*routine(void *cur)
{
	t_philo			*p;
	struct timeval	ct;

	p = (t_philo *)cur;
	while (1)
	{
		if (check_ready(p->ready))
			break ;
	}
	while (!check_died(p))
	{
		gettimeofday(&ct, NULL);
		update_ttd(p, ct);
		if (!get_fork(p))
			return (NULL);
		if (p->rh && p->lh)
		{
			if (!eating(p))
				return (NULL);
		}
		if (!sleeping(p))
			return (NULL);
		print_thinking(p);
	}
	return (NULL);
}

void	thread_process(t_obs *obs, int pn)
{
	create_all_pthread(obs, pn);
	join_all_pthread(obs, pn);
}
