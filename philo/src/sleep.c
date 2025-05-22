/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 09:33:44 by saan              #+#    #+#             */
/*   Updated: 2025/05/17 17:42:18 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_sleeping(t_philo *p)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	while (1)
	{
		if (pthread_mutex_lock(p->m_printf) == 0)
		{
			printf("%ld %d is sleeping\n", cal_ct(p->s_time, ct), p->pn);
			pthread_mutex_unlock(p->m_printf);
			break ;
		}
		else
			continue ;
	}
}

void	sleeping(t_philo *p)
{
	struct timeval	st;
	struct timeval	sst;

	pthread_mutex_unlock(p->r_f);
	p->lr_f = 0;
	pthread_mutex_unlock(p->l_f);
	p->ll_f = 0;
	gettimeofday(&sst, NULL);
	print_sleeping(p);
	while(1)
	{
		gettimeofday(&st, NULL);
		update_ttd(p, st);
		if (p->amid)
			return ;
		if (cal_ct(sst, st) >= p->tts)
			return ;
	}
}
