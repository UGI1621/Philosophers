/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:33:29 by saan              #+#    #+#             */
/*   Updated: 2025/05/27 19:18:14 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_hello(t_philo *p)
{
	struct timeval ct;

	while (1)
	{
		gettimeofday(&ct, NULL);
		update_ttd(p, ct);
		if (check_died(p))
			return ;
		pthread_mutex_lock(p->m_print);
		if (*p->l_print)
		{
			pthread_mutex_unlock(p->m_print);
			continue ;
		}
		printf("%d right fork status %d\n",p->pn, p->rb->status);
		pthread_mutex_unlock(p->m_print);
		return ;
	}
}

void	*obs_routine(void *obs_unit)
{
	t_obs *obs;

	obs = (t_obs *)obs_unit;
	while(1)
	{
		if (find_dead_p(obs))
			return (NULL);
		if ((obs->met != -1) && cal_et(obs))
		{
			write(1, "FUCK\n", 5);
			return (NULL);
		}
	}
}

void	*routine(void *cur)
{
	t_philo *p;
	struct timeval ct;

	p = (t_philo *)cur;
	while (!check_died(p))
	{
		gettimeofday(&ct, NULL);
		update_ttd(p, ct);
		if(!get_fork(p))
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
