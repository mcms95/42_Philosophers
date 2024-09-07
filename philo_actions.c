/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:40:05 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 21:00:28 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philosopher_sleep(t_philo *philos)
{
	long int	nap_time;
	long int	napping;

	nap_time = get_time(MILLISECOND);
	napping = 0;
	if (is_simulation_over())
		return (0);
	print_message(philos, "is sleeping");
	precise_usleep(100);
	while (napping <= data()->time_to_sleep && is_philosopher_alive(philos))
		napping = get_time(MILLISECOND) - nap_time;
	return (1);
}

int	philosopher_eat(t_philo *philo)
{
	long int	eat_time;
	long int	eating;

	eat_time = get_time(MILLISECOND);
	eating = 0;
	if (is_simulation_over())
		return (0);
	precise_usleep(100);
	if (is_philosopher_alive(philo))
	{
		print_message(philo, "is eating");
		while (eating <= data()->time_to_eat && is_philosopher_alive(philo))
			eating = get_time(MILLISECOND) - eat_time;
		philo->time_of_last_meal = get_time(MILLISECOND);
		release_forks(philo, philo->right_fork);
		release_forks(philo, philo->left_fork);
		philo->forks_nbr = 0;
		philo->meals_eaten++;
	}
	return (1);
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philosopher ;

	philosopher = (t_philo *)arg;
	if (philosopher ->id % 2 == 0)
		precise_usleep(70000);
	philosopher ->time_of_last_meal = data()->start_time;
	while (is_philosopher_alive(philosopher))
	{
		attempt_to_eat(philosopher);
		if (philosopher ->meals_eaten == data()->meals_to_eat)
			return (NULL);
		philosopher_sleep(philosopher);
		precise_usleep(100);
		if (!is_simulation_over())
			print_message(philosopher, "is thinking");
	}
	return (NULL);
}

bool	is_philosopher_alive(t_philo *philos)
{
	long	time_since_last_meal;

	if (is_simulation_over())
		return (false);
	time_since_last_meal = get_time(MILLISECOND) - philos->time_of_last_meal;
	if (time_since_last_meal >= philos->data->time_to_die)
	{
		pthread_mutex_lock(&death_status()->death_mutex);
		if (!death_status()->is_dead)
		{
			death_status()->is_dead = true;
			print_message(philos, "died");
		}
		pthread_mutex_unlock(&death_status()->death_mutex);
		return (false);
	}
	return (true);
}

t_philo	*philos_init(void)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = malloc(sizeof(t_philo) * (data()->philo_nbr));
	if (!philos)
		return (NULL);
	while (++i < data()->philo_nbr)
	{
		philos[i].data = data();
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].time_of_last_meal = 0;
		philos[i].sleeping = 0;
		philos[i].forks_nbr = 0;
	}
	return (philos);
}
