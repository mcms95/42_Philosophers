/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:39:52 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 21:13:56 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_forks	*forks_init(void)
{
	t_forks	*forks;
	int		i;

	i = -1;
	forks = malloc(sizeof(t_forks) * (data()->philo_nbr));
	if (!forks)
		return (NULL);
	while (++i < data()->philo_nbr)
	{
		forks[i].has_fork = false;
		pthread_mutex_init(&forks[i].fork_mutex, NULL);
	}
	return (forks);
}

int	attempt_to_eat(t_philo *philo)
{
	philo->right_fork = philo->id;
	philo->left_fork = (philo->id - 1 + data()->philo_nbr) % data()->philo_nbr;
	if (is_philosopher_alive(philo))
	{
		try_pick_up_fork(philo, philo->right_fork);
		try_pick_up_fork(philo, philo->left_fork);
		if (philo->forks_nbr == 2)
			philosopher_eat(philo);
		return (1);
	}
	return (0);
}

void	release_forks(t_philo *phi, int index)
{
	pthread_mutex_lock(&phi->forks[index].fork_mutex);
	phi->forks[index].has_fork = false;
	pthread_mutex_unlock(&phi->forks[index].fork_mutex);
}

int	try_pick_up_fork(t_philo *philosopher, int index)
{
	while (is_philosopher_alive(philosopher))
	{
		pthread_mutex_lock(&philosopher->forks[index].fork_mutex);
		if (philosopher->forks[index].has_fork == 0)
		{
			philosopher->forks[index].has_fork = 1;
			philosopher->forks_nbr += 1;
			log_philosopher_action(philosopher, "has taken a fork");
			pthread_mutex_unlock(&philosopher->forks[index].fork_mutex);
			break ;
		}
		else
			pthread_mutex_unlock(&philosopher->forks[index].fork_mutex);
	}
	return (0);
}

bool	is_simulation_over(void)
{
	bool	is_terminated;

	pthread_mutex_lock(&death_status()->death_mutex);
	is_terminated = death_status()->is_dead;
	pthread_mutex_unlock(&death_status()->death_mutex);
	return (is_terminated);
}
