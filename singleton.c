/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:40:18 by nuno              #+#    #+#             */
/*   Updated: 2024/09/07 20:40:19 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
A singleton in C is a design pattern that ensures only one instance of a class can be created and provides a global point of access to that instance.
In this case we call data() and it returns a pointer to our main struct of type t_data
Access a paramater - data()-> time_to_die;
Can be initialized in any part of the program to be accessible 
*/

t_data	*data(void)
{
	static t_data info;

	return (&info);
}

t_dead	*death_status(void)
{
	static t_dead	death;

	return (&death);
}