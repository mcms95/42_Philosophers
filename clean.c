/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:39:43 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 20:39:44 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_all(t_philo *philos, t_forks *forks)
{
	int	i;

	i = -1;
	if (forks)
	{
		while (++i < data()->philo_nbr)
			pthread_mutex_destroy(&forks[i].fork_mutex);
		free(forks);
	}
	if (philos)
		free(philos);
}