/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:34:55 by saan              #+#    #+#             */
/*   Updated: 2025/04/26 08:33:45 by saan             ###   ########.fr       */
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

void	*ft_calloc(size_t number, size_t size)
{
	void	*temp;

	if (size && (number > 18446744073709551615UL / size))
		return (NULL);
	temp = (void *)malloc(number * size);
	if (!temp)
		return (NULL);
	memset(temp, 0, size);
	return (temp);
}
