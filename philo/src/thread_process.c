/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:33:29 by saan              #+#    #+#             */
/*   Updated: 2025/04/30 10:22:45 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*obs_routine(void *obs_unit)
{
	t_philo *obs;
	struct timeval ct;

	obs = (t_philo *)obs_unit;
	while(1)
	{
		gettimeofday(&ct, NULL);
		if (obs->ttd <= 0)
		{
			printf("%ld %d is dead\n", cal_ct(obs->s_time,ct), obs->pn);
			break ;
		}
		obs = obs->next;
	}
	return (NULL);
}

void	*routine(void *cur)
{
	t_philo *p;

	p = (t_philo *)cur;
	gettimeofday(&p->s_time, NULL);
	while (1)
	{
		if (!get_fork(p))
			continue ;
		else
			break ;
		// if (*p->lr_f && *p->ll_f)
		// 	eating(p);
	}
	return (NULL);
}

void	thread_process(t_obs *obs, int pn)
{
	create_all_pthread(obs, pn);
	join_all_pthread(obs, pn);
}
