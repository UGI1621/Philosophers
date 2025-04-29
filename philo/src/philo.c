/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:16:27 by saan              #+#    #+#             */
/*   Updated: 2025/04/28 11:18:32 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_obs	obs;

	if (!is_valid_args(ac, av))
		return (1);
	if (init_obs(&obs, ft_atoi(av[1])))
		return (1);
	if (init_cdll(&obs, av))
		return (1);
	free_all_nodes(&obs, ft_atoi(av[1]));
	destroy_all_mutex(obs.forks, ft_atoi(av[1]));
	return (0);
}
