/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:12:01 by saan              #+#    #+#             */
/*   Updated: 2025/05/27 17:54:58 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	try_get_lfork_box(t_philo *p)
{
	if (!p->lh)
	{
		pthread_mutex_lock(&p->lb->box);
		if (check_died(p))
		{
			pthread_mutex_unlock(&p->lb->box);
			return ;
		}
		if (p->lb->status)
		{
			p->lb->status = 0;
			p->lh = 1;
			print_got_fork(p);
		}
		pthread_mutex_unlock(&p->lb->box);
	}
}

static void	try_get_rfork_box(t_philo *p)
{
	if (!p->rh)
	{
		pthread_mutex_lock(&p->rb->box);
		if (check_died(p))
		{
			pthread_mutex_unlock(&p->rb->box);
			return ;
		}
		if (p->rb->status)
		{
			p->rb->status = 0;
			p->rh = 1;
			print_got_fork(p);
		}
		pthread_mutex_unlock(&p->rb->box);
	}
}

static void	try_get_fork(t_philo *p)
{
	if (!(p->pn % 2))
	{
		usleep(10);
		try_get_rfork_box(p);
		if (p->rh)
			try_get_lfork_box(p);
	}
	else
	{
		try_get_lfork_box(p);
		if (p->lh)
			try_get_rfork_box(p);
	}
}

int	get_fork(t_philo *p)
{
	struct timeval ct;

	while (!(p->rh && p->lh))
	{
		gettimeofday(&ct, NULL);
		update_ttd(p, ct);
		if (check_died(p))
			return (0);
		try_get_fork(p);
	}
	return (1);
}
