/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:29:46 by saan              #+#    #+#             */
/*   Updated: 2025/05/24 17:26:03 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	die_from_ttd(t_obs *obs, t_philo *cur)
{
	int	i;
	struct timeval	ct;

	i = -1;
	while (1)
	{
		gettimeofday(&ct, NULL);
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
		set_die(cur);
	}
}

int	die_check(t_philo *p)
{
	int flag;

	flag = 0;
	while(1)
	{
		if (pthread_mutex_lock(p->m_amid) == 0)
		{
			if (p->amid)
				flag = 1;
			pthread_mutex_unlock(p->m_amid);
			break;
		}
		else
			continue ;
	}
	return (flag);
}

int	obs_die_check(t_obs *obs)
{
	int	i;
	t_philo *p;

	i = -1;
	p = obs->head;
	while (++i < obs->ph_n)
	{
		if (die_check(p))
		{
			die_from_ttd(obs, p);
			return (1);
		}
		p = p->next;
	}
	return (0);
}
