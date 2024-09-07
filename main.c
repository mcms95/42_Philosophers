/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:39:56 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 21:34:25 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_simulation(void)
{
	int		i;
	t_forks	*forks;
	t_philo	*philos;

	i = -1;
	data()->start_time = get_time(MILLISECOND);
	pthread_mutex_init(&death_status()->death_mutex, NULL);
	philos = philos_init();
	forks = forks_init();
	if (!philos || !forks)
		return (clean_all(philos, forks));
	while (++i < data()->philo_nbr)
		philos[i].forks = forks;
	i = -1;
	while (++i < data()->philo_nbr)
		pthread_create(&philos[i].philo, NULL,
			philosopher_routine, (void *)&philos[i]);
	while (--i > -1)
		pthread_join(philos[i].philo, NULL);
	free(philos);
	i = -1;
	while (++i < data()->philo_nbr)
		pthread_mutex_destroy(&forks[i].fork_mutex);
	free(forks);
	return ;
}

int	main(int ac, char **av)
{
	if (ac == 5 || ac == 6)
	{
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
