/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:55:57 by saan              #+#    #+#             */
/*   Updated: 2025/04/30 12:37:21 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_got_fork(t_philo *p)
{
	struct timeval ct;

	gettimeofday(&ct, NULL);
	while (1)
	{
		if (pthread_mutex_lock(p->m_printf) == 0)
		{
			printf("%ld %d has taken a right fork\n", cal_ct(p->s_time, ct), p->pn);
			printf("%ld %d has taken a left fork\n", cal_ct(p->s_time, ct), p->pn);
			pthread_mutex_unlock(p->m_printf);
			return (1);
		}
		else
			continue ;
	}
}

static int	get_fork_odd(t_philo *p)
{
	if (!*p->lr_f)
	{
		if (pthread_mutex_lock(p->r_f) == 0)
		{
			*p->lr_f = 1;
			if (!*p->ll_f && pthread_mutex_lock(p->l_f) == 0)
			{
				*p->ll_f = 1;
				return (print_got_fork(p));
			}
			else
			{
				// printf("%ld %d has lost a right fork\n", cal_ct(p->s_time, ct), p->pn);
				pthread_mutex_unlock(p->r_f);
				*p->lr_f = 0;
				usleep(100);
			}
		}
	}
	return (0);
}

static int	get_fork_even(t_philo *p)
{
	if (!*p->ll_f)
	{
		if (pthread_mutex_lock(p->l_f) == 0)
		{
			*p->ll_f = 1;
			if (!*p->lr_f &&pthread_mutex_lock(p->r_f) == 0)
			{
				*p->lr_f = 1;
				return (print_got_fork(p));
			}
			else
			{
				// printf("%ld %d has lost a left fork\n", cal_ct(p->s_time, ct), p->pn);
				pthread_mutex_unlock(p->l_f);
				*p->ll_f = 0;
				usleep(100);
			}
		}
	}
	return (0);
}

int	get_fork(t_philo *p)
{
	if (p->pn % 2 == 0)
		return (get_fork_even(p));
	else
		return (get_fork_odd(p));
}
