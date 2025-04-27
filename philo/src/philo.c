/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:16:27 by saan              #+#    #+#             */
/*   Updated: 2025/04/27 07:22:02 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_obs	obs;

	if (!is_valid_args(ac, av))
		return (1);
	init_obs(&obs);
	init_cdll(&obs, av);
	free_all_nodes(&obs);
	return (0);
}
