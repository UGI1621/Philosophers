/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:16:27 by saan              #+#    #+#             */
/*   Updated: 2025/05/12 19:15:43 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_obs	obs;
	struct timeval	ct;

	gettimeofday(&ct, NULL);
	if (!is_valid_args(ac, av))
		return (1);
	if (init_obs(&obs, ft_atoi(av[1]), ac, av))
		return (1);
	if (init_cdll(&obs, av, ct))
		return (1);
	thread_process(&obs, ft_atoi(av[1]));
	free_all_nodes(&obs, ft_atoi(av[1]));
	destroy_all_mutex(obs.forks, ft_atoi(av[1]));
	free(obs.is_lock);
	return (0);
}
