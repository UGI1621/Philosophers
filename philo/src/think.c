/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:33:46 by saan              #+#    #+#             */
/*   Updated: 2025/05/12 19:32:51 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_thinking(t_philo *p)
{
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	while (1)
	{
		if (pthread_mutex_lock(p->m_printf) == 0)
		{
			printf("%ld %d is thinking\n", cal_ct(p->s_time, ct), p->pn);
			pthread_mutex_unlock(p->m_printf);
			break ;
		}
		else
			continue ;
	}
}

int	thinking(t_philo *p)
{
	struct timeval	slt;
	struct timeval	sslt;

	gettimeofday(&sslt, NULL);
	if (p->e_flag > 0)
		print_thinking(p);
	while (1)
	{
		gettimeofday(&slt, NULL);
		update_ttd(p, slt);
		if (p->amid)
			return (-1);
		if (!get_fork(p))
			continue ;
		else if (get_fork(p) == -1)
			return (-1);
		else
			return (0);
	}
}
