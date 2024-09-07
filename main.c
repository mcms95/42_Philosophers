/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:39:56 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 20:39:57 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Input ./philo philo_nbr time_to_die time_to_eat time_to_sleep [meals_to_eat]
void dinner(void);

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
		// Parse input
		if (!parse_arguments(av))
		{
			printf("Invalid arguments\n");
			return (1);
		}
		start_simulation();
	}
	else
	{
		printf("Error: Wrong number of arguments\n");
	}
	return (0);
}

void	start_simulation()
{
	int		i;
	t_forks	*forks;
	t_philo	*philos;

	i = -1;
	data()->start_time = get_time(MILLISECOND);
	death_status()->is_dead = false;
	pthread_mutex_init(&death_status()->death_mutex, NULL);
	philos = philos_init();
	forks = forks_init();
	if (!philos || !forks)
		return (clean_all(philos, forks));
	while (++i < data()->philo_nbr)
		philos[i].forks = forks;
	i = -1;
	printf("Start time: %ld\n", data()->start_time);
	printf("Starting dinner\n");
	while (++i < data()->philo_nbr)
		pthread_create(&philos[i].philo, NULL, philosopher_routine, (void *)&philos[i]);
	printf("Joining threads\n");
	while (--i > -1)
		pthread_join(philos[i].philo, NULL);
	free(philos);
	i = -1;
	printf("Cleaning forks\n");
	while (++i < data()->philo_nbr)
		pthread_mutex_destroy(&forks[i].fork_mutex);
	free(forks);
	return ;
}

bool is_simulation_over(void)
{
    bool corpse;

    pthread_mutex_lock(&death_status()->death_mutex);
    corpse = death_status()->is_dead;
    pthread_mutex_unlock(&death_status()->death_mutex);
    return corpse;
}
