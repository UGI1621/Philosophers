/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:21:50 by saan              #+#    #+#             */
/*   Updated: 2025/05/27 18:39:59 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	put_down_lfork(t_philo *p)
{
	pthread_mutex_lock(&p->lb->box);
	if (check_died(p))
	{
		pthread_mutex_unlock(&p->lb->box);
		return (0);
	}
	p->lh = 0;
	p->lb->status = 1;
	pthread_mutex_unlock(&p->lb->box);
	return (1);
}

static	int	put_down_rfork(t_philo *p)
{
	pthread_mutex_lock(&p->rb->box);
	if (check_died(p))
	{
		pthread_mutex_unlock(&p->rb->box);
		return (0);
	}
	p->rh = 0;
	p->rb->status = 1;
	pthread_mutex_unlock(&p->rb->box);
	return (1);
}

static int	add_et(t_philo *p)
{
	pthread_mutex_lock(p->status.box);
	if (p->status.d)
	{
		pthread_mutex_unlock(p->status.box);
		return (0);
	}
	p->status.et++;
	pthread_mutex_unlock(p->status.box);
	if (!(p->pn % 2))
	{
		if (!(put_down_rfork(p) && put_down_lfork(p)))
			return (0);
	}
	else
	{
		if (!(put_down_lfork(p) && put_down_rfork(p)))
			return (0);
	}
	return (1);
}

int	eating(t_philo *p)
{
	struct timeval	et;
	struct timeval	set;

	gettimeofday(&set, NULL);
	print_eating(p);
	p->ttd = p->init_ttd;
	while (1)
	{
		gettimeofday(&et, NULL);
		update_ttd(p, et);
		if (check_died(p))
			return (0);
		if (cal_ct(set, et) >= p->tte)
			return (add_et(p));
	}
}
