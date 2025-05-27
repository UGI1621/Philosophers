/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:33:29 by saan              #+#    #+#             */
/*   Updated: 2025/05/24 15:03:57 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	count_et(t_obs *obs, t_philo *p)
{
	int	i;
	t_philo *cur;

	i = -1;
	cur = obs->head;
	obs->ml_printf = 1;
	while (++i < obs->ph_n)
	{
		if (!(cur->et >= obs->met))
		{
			obs->ml_printf = 0;
			return (0);
		}
		cur = cur->next;
	}
	i = -1;
	while (++i < obs->ph_n)
	{
		set_die(cur);
		cur = cur->next;
	}
	return (1);
}

void	*obs_routine(void *obs_unit)
{
	t_obs *obs;
	t_philo *cur;

	obs = (t_obs *)obs_unit;
	cur = obs->head;
	while(1)
	{
		if(obs_die_check(obs))
			return (NULL);
		if (obs->met != -1 && count_et(obs, cur))
			return (NULL);
		cur = cur->next;
	}
	return (NULL);
}

void	*routine(void *cur)
{
	t_philo *p;
	struct timeval ct;

	p = (t_philo *)cur;
	while (1)
	{
		gettimeofday(&ct, NULL);
		update_ttd(p, ct);
		if (die_check(p))
			return (NULL);
		if (thinking(p) == -1)
			return (NULL);
		// eating(p);
		// sleeping(p);
	}
	return (NULL);
}

void	thread_process(t_obs *obs, int pn)
{
	create_all_pthread(obs, pn);
	join_all_pthread(obs, pn);
}
