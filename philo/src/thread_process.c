/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:33:29 by saan              #+#    #+#             */
/*   Updated: 2025/04/30 12:48:53 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*obs_routine(void *obs_unit)
{
	t_obs *obs;
	t_philo *cur;
	struct timeval ct;
	int	i;

	i = -1;
	obs = (t_obs *)obs_unit;
	cur = obs->head;
	while(1)
	{
		gettimeofday(&ct, NULL);
		if (cur->ttd <= 0)
		{
			printf("%ld %d is dead\n", cal_ct(cur->s_time,ct), cur->pn);
			while (++i < obs->ph_n)
			{
				cur = cur->next;
				printf("obs kill everyone pn : %d\n", cur->pn);
				cur->amid = 1;
			}
			break ;
		}
		cur = cur->next;
		// usleep(500);
	}
	return (NULL);
}

void	*routine(void *cur)
{
	t_philo *p;

	p = (t_philo *)cur;
	gettimeofday(&p->s_time, NULL);
	while (1)
	{
		update_ttd(p);
		if (p->amid)
			break ;
		if (!get_fork(p))
			continue ;

	}
	return (NULL);
}

void	thread_process(t_obs *obs, int pn)
{
	create_all_pthread(obs, pn);
	join_all_pthread(obs, pn);
}
