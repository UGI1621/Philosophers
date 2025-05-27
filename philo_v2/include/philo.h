/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saan <saan@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 06:14:52 by saan              #+#    #+#             */
/*   Updated: 2025/05/27 19:15:47 by saan             ###   ########.fr       */
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

typedef struct s_fork
{
	pthread_mutex_t box;
	int	status;
}	t_fork;

typedef struct s_p_stat
{
	pthread_mutex_t	*box;
	int	d;
	int	et;
}	t_p_stat;

typedef struct s_philo
{
	struct s_philo	*prev;
	pthread_t		tid;
	int				pn;		// philo num
	int				init_ttd;
	int				ttd;	// time to die
	int				tte;	// time to eat
	int				tts;	// time to sleep
	int				rh;
	int				lh;
	t_fork			*rb;
	t_fork			*lb;
	t_p_stat		status;
	int				*l_print;
	pthread_mutex_t	*m_print;
	struct timeval	s_time;
	struct s_philo	*next;
}					t_philo;

typedef struct s_obs
{
	t_philo			*head;
	pthread_t		tid;
	int				ph_n;
	int				met;
	t_fork			*forks;
	int				l_print;
	t_philo			*tail;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_stat;
}					t_obs;

// error.c
int				e_w_m(char *e_str);
int				e_w_f(char *e_str, t_obs *obs, int pn);

// atoi.c
int					ft_atoi(const char *nptr);

// util.c
void				free_all_nodes(t_obs *obs, int pn);
void				destroy_forks_mutex(pthread_mutex_t *forks, int idx);
void				join_all_pthread(t_obs *obs, int pn);
int					ft_strcmp(char *str1, char *str2);
void				*ft_calloc(size_t number, size_t size);

// util2.c
void	update_ttd(t_philo *p, struct timeval ct);
long	cal_ct(struct timeval st, struct timeval ct);
void	create_all_pthread(t_obs *obs, int pn);
int		cal_et(t_obs *obs);

// initialization.c
int	init_obs(t_obs *obs, int pn, int ac, char *av[]);
int	init_cdll(t_obs *obs, char *av[], struct timeval ct);

// thread_process.c
void	print_hello(t_philo *p);
void	thread_process(t_obs *obs, int pn);
void	*routine(void *cur);
void	*obs_routine(void *obs_unit);

// fork.c
int	get_fork(t_philo *p);

// eat.c
int	eating(t_philo *p);

// die.c
int	check_died(t_philo *p);
void	set_died(t_philo *p);
int	find_dead_p(t_obs *obs);

// sleep.c
int	sleeping(t_philo *p);

// print.c
void	print_got_fork(t_philo *p);
void	print_eating(t_philo *p);
void	print_sleeping(t_philo *p);
void	print_thinking(t_philo *p);
void	print_die(t_philo *p);

#endif
