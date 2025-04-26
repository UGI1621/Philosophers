/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 09:09:44 by saan              #+#    #+#             */
/*   Updated: 2025/04/26 09:13:54 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_node(t_philo *node)
{
	if (node->ttd < 0 || node->tte < 0 || node->tts < 0)
		return (0);
	if (node->tte)
		if (node->tte < 0)
			return (0);
	return (1);
}
