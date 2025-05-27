/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:31:26 by saan              #+#    #+#             */
/*   Updated: 2025/05/27 19:20:16 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_ttd(t_philo *p, struct timeval ct)
{
	struct timeval now;

	while (1)
	{
		gettimeofday(&now, NULL);
		if (cal_ct(ct, now) > 0)
		{
			p->ttd -= cal_ct(ct, now);
			if (p->ttd <= 0)
			{
				print_die(p);
				set_died(p);
			}
			return ;
		}
	}
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
	pthread_create(&obs->tid, NULL, obs_routine, obs);
	while (++i < pn)
	{
		pthread_create(&cur->tid, NULL, routine, cur);
		cur = cur->next;
		cur->s_time = stime;
	}
}

int		cal_et(t_obs *obs)
{
	int	i;
	int	all_et;
	int	flag;
	t_philo *p;

	i = -1;
	p = obs->head;
	flag = 0;
	all_et = 0;
	pthread_mutex_lock(&obs->m_stat);
	while (++i < obs->ph_n)
	{
		if (p->status.et > obs->met)
			all_et += obs->met;
		else
			all_et += p->status.et;
		if (all_et >= (obs->met * obs->ph_n))
		{
			flag = 1;
			break ;
		}
		p = p->next;
	}
	pthread_mutex_unlock(&obs->m_stat);
	return (flag);
}
