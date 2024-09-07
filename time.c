/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:40:34 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 21:06:05 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(t_time_code time_code)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (time_code == SECOND)
		return (tv.tv_sec + tv.tv_usec / 1000000);
	else if (time_code == MILLISECOND)
		return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
	else if (time_code == MICROSECOND)
		return ((tv.tv_sec * 1000000) + tv.tv_usec);
	else
		printf("Invalid time code\n");
	return (0);
}

void	precise_usleep(long time_in_usec)
{
	long	start;
	long	elapsed_time;
	long	remaining_time;

	start = get_time(MICROSECOND);
	while (get_time(MICROSECOND) - start < time_in_usec)
	{
		elapsed_time = get_time(MICROSECOND) - start;
		remaining_time = time_in_usec - elapsed_time;
		if (remaining_time > 1000)
			usleep(time_in_usec / 2);
		else
		{
			while (get_time(MICROSECOND) - start < time_in_usec)
				;
		}
	}
}
