/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:34:01 by saan              #+#    #+#             */
/*   Updated: 2025/04/27 11:17:55 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	e_w_m(char *e_str)
{
	if(!ft_strcmp("ivac", e_str))
		printf("Useage : ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	if(!ft_strcmp("ivpn", e_str))
		printf("Error : invalid philosopher num\n");
	if(!ft_strcmp("ivav", e_str))
		printf("Error : invalid argument value\n");
	return (1);
}
