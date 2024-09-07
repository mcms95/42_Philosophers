/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:40:02 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 20:40:03 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	parse_arguments(char **av)
{
	// Valid number checked
	if (!is_valid_number(av[1]) || !is_valid_number(av[2]) 
		|| !is_valid_number(av[3]) || !is_valid_number(av[4]))
		return (0);
	if (!is_within_valid_range(ft_atoi(av[1])) || !is_within_valid_range(ft_atoi(av[2])) 
		||!is_within_valid_range(ft_atoi(av[3])) ||!is_within_valid_range(ft_atoi(av[4])))
		return (0);
	data()->philo_nbr = ft_atoi(av[1]);
	data()->time_to_die = ft_atoi(av[2]);
	data()->time_to_eat = ft_atoi(av[3]);
	data()->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	{
		if (is_valid_number(av[5]))
		{
			if (is_within_valid_range(ft_atoi(av[5])))
				data()->meals_to_eat = ft_atoi(av[5]);
		}
		else 
			return (0);
	}
	return (1);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (0);
			
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int is_within_valid_range(int number)
{
	if (number <= 0 || number > INT_MAX)
		return (0);
	return (1);
}

int	ft_atoi(char *str)
{
	long	number;
	int		i;

	i = 0;
	number = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return ((int)number);
}