/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:40:14 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 21:13:53 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>

// Time code
typedef enum e_time_code
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}	t_time_code;

typedef struct s_data	t_data;
typedef struct s_dead	t_dead;
typedef struct s_forks	t_forks;
typedef struct s_philo	t_philo;

struct	s_data
{
	int				time_to_die;
	int				time_to_sleep;
	int				time_to_think;
	int				meals_to_eat;
	int				time_to_eat;
	int				philo_nbr;
	long			start_time;
	t_data			*data;
	t_dead			*death;
	t_forks			*forks;
	t_philo			*philos;
};

struct	s_dead
{
	bool			is_dead;
	pthread_mutex_t	death_mutex;
};

struct	s_forks
{
	bool			has_fork;
	pthread_mutex_t	fork_mutex;
};

struct	s_philo
{
	int				id;
	int				meals_eaten;
	long int		time_of_last_meal;
	long int		sleeping;
	int				forks_nbr;
	int				left_fork;
	int				right_fork;
	pthread_t		philo;
	t_data			*data;
	t_dead			*death;
	t_forks			*forks;
};

// clean.c
void	clean_all(t_philo *philos, t_forks *forks);

// forks.c
t_forks	*forks_init(void);
int		attempt_to_eat(t_philo *phi);
void	release_forks(t_philo *phi, int index);
int		try_pick_up_fork(t_philo *phi, int index);
bool	is_simulation_over(void);

// logger.c
void	log_philosopher_action(t_philo *philos, char *str);

// main.c
void	start_simulation(void);

// parsing.c
int		parse_arguments(char **av);
int		is_valid_number(char *str);
int		is_within_valid_range(int number);
int		ft_atoi(char *str);

// philos.c
int		philosopher_sleep(t_philo *philos);
int		philosopher_eat(t_philo *philos);
void	*philosopher_routine(void *arg);
bool	is_philosopher_alive(t_philo *philos);
t_philo	*philos_init(void);

// Singleton.c
t_data	*data(void);
t_dead	*death_status(void);

// time.c
long	get_time(t_time_code time_code);
void	precise_usleep(long time_in_usec);

#endif