/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:14:52 by saan              #+#    #+#             */
/*   Updated: 2025/04/26 07:21:34 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_philo	*prev;
	int				pn;		// philo num
	int				l_h;	// left hand
	int				r_h;	// right hand
	int				ttd;	// time to die
	int				tte;	// time to eat
	int				tts;	// time to sleep
	int				met;	// must eat time
	struct s_philo	*next;
}					t_philo;

typedef struct s_obs
{
	t_philo			*next;
	int				is_dead;	// anyone dead?
	int				is_met;		// every one finish?
}					t_obs;

void				e_w_m(char *e_str);

int					ft_strcmp(char *str1, char *str2);

#endif
