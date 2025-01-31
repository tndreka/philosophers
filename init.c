/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:01 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/29 11:56:28 by tndreka          ###   ########.fr       */
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
/*
	here we assign the 
*/
void data_assign(t_dining *dining)
{
	t_secure	data;
	int			i;

	i = 0;
	dining->finish_routine = false;
	dining->philos = (t_philo *)alloc_malloc(sizeof(t_philo) * dining->philo_nbr);
	dining->forks = (t_fork *)alloc_malloc(sizeof(t_fork) * dining->philo_nbr);
	while (i < dining->philo_nbr)
	{
		data.data1 = &dining->forks[i].fork;
		data.code = MUTEX_INIT;
		secure_function(&data);
		i++;
	}	
}
void create_philos(t_dining *dining)
{
	t_philo		*philo;
	int			i;

	i = 0;
	while (i < dining->philo_nbr)
	{
		philo = &dining->philos[i];
		philo->full = false;
		philo->meal_count = 0;
		philo->dining = dining;
		
		i++;
	}
	
}
