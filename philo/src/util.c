/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:34:55 by saan              #+#    #+#             */
/*   Updated: 2025/04/26 06:39:12 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	len;
	int	i;

	len = 0;
	while (str1[len])
		len++;
	i = 0;
	while (str1[i] && str2[i] && i < len)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if ((str1[i] || str2[i]) && (str1[i] != str2[i]))
		return (str1[i] - str2[i]);
	return (0);
}
