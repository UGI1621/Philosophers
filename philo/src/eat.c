/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 09:25:35 by saan              #+#    #+#             */
/*   Updated: 2025/05/23 19:44:02 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_eating(t_philo *p)
{
	struct timeval	ct;

	while (1)
	{
		gettimeofday(&ct, NULL);
		update_ttd(p, ct);
		if (p->amid)
			break ;
		if (*p->ml_pinrtf)
			continue ;
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
			while (1)
			{
				if (pthread_mutex_lock(p->m_et) == 0)
				{
					p->et++;
					pthread_mutex_unlock(p->m_et);
					return ;
				}
				else
					continue ;
			}
		}
	}
}
