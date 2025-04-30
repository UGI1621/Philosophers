/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:14:52 by saan              #+#    #+#             */
/*   Updated: 2025/04/30 11:38:30 by saan             ###   ########.fr       */
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
	pthread_mutex_t				*l_f;	// left fork
	int							*ll_f;
	pthread_mutex_t				*r_f;	// right fork
	int							*lr_f;
	int				init_ttd;
	int				ttd;	// time to die
	int				tte;	// time to eat
	int				tts;	// time to sleep
	int				met;	// must eat time
	int				amid;
	pthread_mutex_t *m_printf;
	struct timeval	s_time;
	struct s_philo	*next;
}					t_philo;

typedef struct s_obs
{
	t_philo			*head;
	pthread_t		tid;
	pthread_mutex_t	m_printf;
	int				ph_n;
	int				is_dead;	// anyone dead?
	int				is_met;		// every one finish?
	t_philo			*tail;
	int				*is_lock;
	pthread_mutex_t	*forks;
}					t_obs;

// error.c
int				e_w_m(char *e_str);
int				e_w_f(char *e_str, t_obs *obs, int pn);

// atoi.c
int					ft_atoi(const char *nptr);

// util.c
void				free_all_nodes(t_obs *obs, int pn);
void				destroy_all_mutex(pthread_mutex_t *forks, int idx);
void				join_all_pthread(t_obs *obs, int pn);
int					ft_strcmp(char *str1, char *str2);
void				*ft_calloc(size_t number, size_t size);

// util2.c
void	update_ttd(t_philo *p);
long	cal_ct(struct timeval st, struct timeval ct);
void	create_all_pthread(t_obs *obs, int pn);

// init.c
int	init_obs(t_obs *obs, int pn);
int	init_cdll(t_obs *obs, char *av[]);

// vali.c
int	is_valid_args(int ac, char *av[]);

// thread.c
void	thread_process(t_obs *obs, int pn);
void	*routine(void *cur);
void	*obs_routine(void *obs_unit);

// fork.c
int	get_fork(t_philo *p);

#endif

