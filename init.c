/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:01 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/28 19:18:15 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
				INITIALIZATION
	On this file we are feeding the struct with all the nescesary data that 
	we need for our program to start.
	
*/
void	initialization(t_dining *dining, int argc, char *argv[])
{
	dining->philo_nbr = ft_atoi(argv[1]);
	dining->time_to_die = ft_atoi(argv[2]) * 1000;
	dining->time_to_eat = ft_atoi(argv[3]) * 1000;
	dining->time_to_sleep = ft_atoi(argv[4]) * 1000;
	if (!argv[5])
		dining->meal_flag = -1;
	else
		dining->meal_flag = ft_atoi(argv[5]);
}
/ *here we assign the 
*/
void data_assign(t_dining *dining)
{
	t_secure	secure_info;  
	int			i;

	i = 0;
	dining->finish_routine = false;/
	dining->philos = (t_philo *)alloc_malloc(sizeof(t_philo) * dining->philo_nbr);
	while (i < dining->philo_nbr)
	{
			
	}
	
}
