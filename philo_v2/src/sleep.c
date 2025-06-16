/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:41:32 by saan              #+#    #+#             */
/*   Updated: 2025/06/16 19:04:49 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *p)
{
	struct timeval	st;
	struct timeval	sst;

	gettimeofday(&sst, NULL);
	print_sleeping(p);
	while (1)
	{
		gettimeofday(&st, NULL);
		update_ttd(p, st);
		if (check_died(p))
			return (0);
		if (cal_ct(sst, st) >= p->tts)
			return (1);
	}
}
