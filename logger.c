/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:40:10 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 21:14:02 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log_philosopher_action(t_philo *philos, char *str)
{
	printf("%ld %i %s\n", get_time(MILLISECOND)
		- philos->data->start_time, philos->id, str);
	return ;
}
