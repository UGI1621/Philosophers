/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:25:35 by saan              #+#    #+#             */
/*   Updated: 2025/05/12 19:32:29 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_eating(t_philo *p)
{
	struct timeval	ct;

	while (1)
	{
		gettimeofday(&ct, NULL);
		if (pthread_mutex_lock(p->m_printf) == 0)
		{
			printf("%ld %d is eating\n", cal_ct(p->s_time, ct), p->pn);
			pthread_mutex_unlock(p->m_printf);
			break ;
		}
		else
		continue ;
	}
	p->ttd = p->init_ttd;
}

void	eating(t_philo *p)
{
	struct timeval	et;
	struct timeval	set;

	gettimeofday(&set, NULL);
	print_eating(p);
	while (1)
	{
		gettimeofday(&et, NULL);
		update_ttd(p, et);
		if (p->amid)
			return ;
		if (cal_ct(set, et) >= p->tte)
		{
			// if (pthread_mutex_lock(p->m_printf) == 0)
			// {
			// 	printf("%ld %d is put down forks\n", cal_ct(p->s_time, et), p->pn);
			// 	pthread_mutex_unlock(p->m_printf);
			// }
			p->et++;
			p->e_flag = 1;
			return ;
		}
	}
}
