/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:09:44 by saan              #+#    #+#             */
/*   Updated: 2025/04/27 11:20:07 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_args(int ac, char *av[])
{
	if (!(ac > 4 && ac < 7))
	{
		printf("Error : invalid argument number\n");
		return (!e_w_m("ivac"));
	}
	if (ft_atoi(av[1]) < 1)
		return (!e_w_m("ivpn"));
	if (ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0
		|| ft_atoi(av[4]) < 0)
		return (!e_w_m("ivav"));
	if (av[5])
		if (ft_atoi(av[5]) < 0)
			return (!e_w_m("ivav"));
	return (1);
}
