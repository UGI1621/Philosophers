/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:14:52 by saan              #+#    #+#             */
/*   Updated: 2025/04/27 11:17:30 by saan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	struct s_philo	*prev;
	pthread_t		tid;
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
	t_philo			*head;
	int				is_dead;	// anyone dead?
	int				is_met;		// every one finish?
	t_philo			*tail;
}					t_obs;

// error.c
int				e_w_m(char *e_str);

// atoi.c
int					ft_atoi(const char *nptr);

// util.c
void				free_all_nodes(t_obs *obs);
int					ft_strcmp(char *str1, char *str2);
void				*ft_calloc(size_t number, size_t size);

// init.c
void	init_obs(t_obs *obs);
void	init_cdll(t_obs *obs, char *av[]);

// vali.c
int	is_valid_args(int ac, char *av[]);

#endif
