/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:31:26 by saan              #+#    #+#             */
/*   Updated: 2025/06/16 19:04:39 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_ttd(t_philo *p, struct timeval ct)
{
	struct timeval	now;

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
	t_philo			*cur;
	struct timeval	stime;
	int				i;

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
	pthread_mutex_lock(&obs->ready.box);
	obs->ready.ready = 1;
	pthread_mutex_unlock(&obs->ready.box);
}

static void	cal_et(t_obs *obs, t_philo *p, int *flag, int *done)
{
	int	i;

	i = -1;
	while (++i < obs->ph_n)
	{
		if (obs_check_died(p))
		{
			set_all_died(obs);
			*flag = 1;
		}
		if (obs->met != -1)
		{
			if (p->status.et >= obs->met)
				(*done)++;
			if (*done == obs->ph_n)
			{
				pthread_mutex_lock(&obs->m_print);
				obs->l_print = 1;
				set_all_died(obs);
				pthread_mutex_unlock(&obs->m_print);
				*flag = 1;
			}
		}
		p = p->next;
	}
}

int	check_end(t_obs *obs)
{
	int		done;
	int		flag;
	t_philo	*p;

	p = obs->head;
	flag = 0;
	done = 0;
	pthread_mutex_lock(&obs->m_stat);
	cal_et(obs, p, &flag, &done);
	pthread_mutex_unlock(&obs->m_stat);
	return (flag);
}
