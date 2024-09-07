/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:40:10 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 21:03:52 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *philos, char *str)
{
	printf("%ld %i %s\n", get_time(MILLISECOND)
		- philos->data->start_time, philos->id, str);
	return ;
}
