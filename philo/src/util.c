/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:34:55 by saan              #+#    #+#             */
/*   Updated: 2025/04/29 22:20:55 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_all_pthread(t_obs *obs, int pn)
{
	int	i;
	t_philo *cur;

	i = -1;
	cur = obs->head;
	while (++i < pn)
	{
		pthread_join(cur->tid, NULL);
		cur = cur->next;
	}
}

void	destroy_all_mutex(pthread_mutex_t *forks, int idx)
{
	int i;

	i = -1;
	while (++i < idx)
		pthread_mutex_destroy(&forks[i]);
	free(forks);
}

void	free_all_nodes(t_obs *obs, int pn)
{
	t_philo *cur;
	t_philo *temp;
	int i;

	i = -1;
	cur = obs->head;
	while(++i < pn)
	{
		temp = cur;
		cur = temp->next;
		free(temp);
	}
}

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
	memset(temp, 0, number * size);
	return (temp);
}
