/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:33:29 by saan              #+#    #+#             */
/*   Updated: 2025/05/11 19:45:50 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	die_from_ttd(t_obs *obs, t_philo *cur, struct timeval ct)
{
	int	i;

	i = -1;
	while (1)
	{
		if (pthread_mutex_lock(cur->m_printf) == 0)
		{
			printf("%ld %d died\n", cal_ct(cur->s_time, ct), cur->pn);
			pthread_mutex_unlock(cur->m_printf);
			break ;
		}
		else
			continue ;
	}
	while (++i < obs->ph_n)
	{
		cur = cur->next;
		cur->amid = 1;
	}
}

void	*obs_routine(void *obs_unit)
{
	t_obs *obs;
	t_philo *cur;
	struct timeval ct;

	obs = (t_obs *)obs_unit;
	cur = obs->head;
	while(1)
	{
		gettimeofday(&ct, NULL);
		if (cur->ttd <= 0)
		{
			die_from_ttd(obs, cur, ct);
			return (NULL);
		}
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
		if (p->amid)
			return (NULL);
		if (!get_fork(p))
			continue ;
		else if (get_fork(p) == -1)
			return (NULL);
		if (p->ll_f && p->lr_f)
			eating(p);
		if (p->et > 0)
			sleeping(p);
	}
	return (NULL);
}

void	thread_process(t_obs *obs, int pn)
{
	create_all_pthread(obs, pn);
	join_all_pthread(obs, pn);
}
