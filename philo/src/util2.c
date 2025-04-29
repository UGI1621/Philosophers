/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:31:26 by saan              #+#    #+#             */
/*   Updated: 2025/04/29 23:48:08 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	int	i;

	i = -1;
	cur = obs->head;
	while (++i < pn)
	{
		gettimeofday(&cur->s_time, NULL);
		pthread_create(&cur->tid, NULL, routine, cur);
		cur = cur->next;
	}
}
