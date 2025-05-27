/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 17:22:49 by saan              #+#    #+#             */
/*   Updated: 2025/05/27 18:44:45 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_thinking(t_philo *p)
{
	struct timeval	ct;

	pthread_mutex_lock(p->m_print);
	if (*p->l_print)
	{
		pthread_mutex_unlock(p->m_print);
		return ;
	}
	gettimeofday(&ct, NULL);
	printf("%ld %d is thinking\n", cal_ct(p->s_time, ct), p->pn);
	pthread_mutex_unlock(p->m_print);
}

void	print_sleeping(t_philo *p)
{
	struct timeval	ct;

	pthread_mutex_lock(p->m_print);
	if (*p->l_print)
	{
		pthread_mutex_unlock(p->m_print);
		return ;
	}
	gettimeofday(&ct, NULL);
	printf("%ld %d is sleeping\n", cal_ct(p->s_time, ct), p->pn);
	pthread_mutex_unlock(p->m_print);
}

void	print_eating(t_philo *p)
{
	struct timeval	ct;

	pthread_mutex_lock(p->m_print);
	if (*p->l_print)
	{
		pthread_mutex_unlock(p->m_print);
		return ;
	}
	gettimeofday(&ct, NULL);
	printf("%ld %d is eating\n", cal_ct(p->s_time, ct), p->pn);
	pthread_mutex_unlock(p->m_print);
}

void	print_got_fork(t_philo *p)
{
	struct timeval	ct;

	pthread_mutex_lock(p->m_print);
	if (*p->l_print)
	{
		pthread_mutex_unlock(p->m_print);
		return ;
	}
	gettimeofday(&ct, NULL);
	printf("%ld %d has taken a fork\n", cal_ct(p->s_time, ct), p->pn);
	pthread_mutex_unlock(p->m_print);
}

void	print_die(t_philo *p)
{
	struct timeval	ct;

	pthread_mutex_lock(p->m_print);
	if (!*p->l_print)
	*p->l_print = 1;
	else
	{
		pthread_mutex_unlock(p->m_print);
		return ;
	}
	gettimeofday(&ct, NULL);
	printf("%ld %d is died\n", cal_ct(p->s_time, ct), p->pn);
	pthread_mutex_unlock(p->m_print);
}
