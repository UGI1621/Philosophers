/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 15:14:36 by saan              #+#    #+#             */
/*   Updated: 2025/06/16 19:31:29 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_args(int ac, char *av[])
{
	if (!(ac > 4 && ac < 7))
	{
		printf("Error : invalid argument number\n");
		return (!e_w_m("ivac"));
	}
	if (ft_atoi(av[1]) < 1)
		return (!e_w_m("ivpn"));
	if (ft_atoi(av[2]) < 0 || ft_atoi(av[3]) < 0 || ft_atoi(av[4]) < 0)
		return (!e_w_m("ivav"));
	if (av[5])
		if (ft_atoi(av[5]) <= 0)
			return (!e_w_m("ivav"));
	return (1);
}

int	main(int ac, char *av[])
{
	t_obs			obs;
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	if (!is_valid_args(ac, av))
		return (1);
	if (init_obs(&obs, ft_atoi(av[1]), av))
		return (1);
	if (init_cdll(&obs, av, ct))
		return (1);
	thread_process(&obs, ft_atoi(av[1]));
	free_all_nodes(&obs, ft_atoi(av[1]));
	destroy_all_mutex(&obs);
	return (0);
}
