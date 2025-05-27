/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:31:26 by saan              #+#    #+#             */
/*   Updated: 2025/05/24 14:40:16 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_die(t_philo *p)
{
	while(1)
	{
		if (pthread_mutex_lock(p->m_amid) == 0)
		{
			p->amid = 1;
			pthread_mutex_unlock(p->m_amid);
			return ;
		}
		else
			continue;
	}
}

void	update_ttd(t_philo *p, struct timeval ct)
{
	struct timeval now;
	// long	elapsed_ms;

	while (1)
	{
		gettimeofday(&now, NULL);
		if (cal_ct(ct, now) > 0)
		{
			p->ttd -= cal_ct(ct, now);
			if (p->ttd <= 0)
				set_die(p);
			return ;
		}
	}
	// printf("%ld \n", elapsed_ms);
	// p->ttd = p->init_ttd - elapsed_ms;
}

long	cal_ct(struct timeval st, struct timeval ct)
{
	long	sec;
	long	usec;

	sec = ct.tv_sec - st.tv_sec;
	usec = ct.tv_usec - st.tv_usec;
	return (sec * 1000 + usec / 1000);
}

void	create_all_pthread(t_obs *obs, int pn)
{
	t_philo *cur;
	struct timeval	stime;
	int	i;

	i = -1;
	cur = obs->head;
	gettimeofday(&stime, NULL);
	cur->s_time = stime;
	while (++i < pn)
	{
		pthread_create(&cur->tid, NULL, routine, cur);
		cur = cur->next;
		cur->s_time = stime;
	}
	pthread_create(&obs->tid, NULL, obs_routine, obs);
}
