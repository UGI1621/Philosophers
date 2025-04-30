/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:31:26 by saan              #+#    #+#             */
/*   Updated: 2025/04/30 10:22:06 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_ttd(t_philo *p)
{
	struct timeval now;
	gettimeofday(&now, NULL);

	// 항상 initial_ttd 기준으로 계산 (절대 기준)
	long elapsed_ms = cal_ct(p->s_time, now); // ms
	p->ttd = p->init_ttd - elapsed_ms;

	if (p->ttd < 0)
		p->ttd = 0;  // 아래 조건 체크가 안 된다면 여기서 잘라주는 것도 고려 가능

	// if (p->ll_f && p->lr_f)
	// 	printf("%ld %d's ttd is : %d\n", elapsed_ms, p->pn, p->ttd);
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
	int	i;

	i = -1;
	cur = obs->head;
	while (++i < pn)
	{
		gettimeofday(&cur->s_time, NULL);
		pthread_create(&cur->tid, NULL, routine, cur);
		cur = cur->next;
	}
	pthread_create(&obs->tid, NULL, obs_routine, &obs->head);
}
