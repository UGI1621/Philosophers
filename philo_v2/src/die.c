/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 16:37:41 by saan              #+#    #+#             */
/*   Updated: 2025/06/16 19:02:48 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_died(t_philo *p)
{
	int	flag;

	flag = 0;
	pthread_mutex_lock(p->status.box);
	if (p->status.d)
		flag = 1;
	pthread_mutex_unlock(p->status.box);
	return (flag);
}

void	set_died(t_philo *p)
{
	pthread_mutex_lock(p->status.box);
	p->status.d = 1;
	pthread_mutex_unlock(p->status.box);
}

void	set_all_died(t_obs *obs)
{
	int		i;
	t_philo	*p;

	i = -1;
	p = obs->head;
	while (++i < obs->ph_n)
	{
		p->status.d = 1;
		p = p->next;
	}
}

int	obs_check_died(t_philo *p)
{
	int	flag;

	flag = 0;
	if (p->status.d)
		flag = 1;
	return (flag);
}
