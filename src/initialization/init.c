/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:01 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/23 16:20:14 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_dining(t_dining *dining, char *argv[])
{
	if (initialization_of_struct(dining, argv) != 0)
	{
		ft_puterr("Error: initialization_of_struct failed !!", 2);
		return (1);
	}
	if (assign_data(dining) != 0)
	{
		ft_puterr("Error: Assign-data failed !!", 2);
		return (1);
	}
	if (init_philo_mutex(dining) != 0)
		return (1);
	if (init_mutex_philo(dining) != 0)
	{
		ft_puterr("Error: init_mutex_philo failed !!", 2);
		return (1);
	}
	if (create_philo(dining) != 0)
	{
		ft_puterr("Error: create_philo failed !!", 2);
		return (1);
	}
	return (0);
}

int	initialization_of_struct(t_dining *dining, char *av[])
{
	if (!av)
		return (1);
	dining->philo_nbr = ft_atoi(av[1]);
	dining->time_to_die = ft_atoi(av[2]);
	dining->time_to_eat = ft_atoi(av[3]);
	dining->time_to_sleep = ft_atoi(av[4]);
	if (!av[5])
		dining->meal_flag = -1;
	else
		dining->meal_flag = ft_atoi(av[5]);
	return (0);
}

int	assign_data(t_dining *dining)
{
	dining->finish_routine = false;
	dining->philos = malloc(sizeof(t_philo) * dining->philo_nbr);
	if (dining->philos == NULL)
	{
		ft_puterr("Malloc for dining->philos failed\n", 2);
		return (1);
	}
	dining->forks = malloc(sizeof(t_fork) * dining->philo_nbr);
	if (dining->forks == NULL)
	{
		free(dining->philos);
		dining->philos = NULL;
		ft_puterr("Malloc for dining->forks failed\n", 2);
		return (1);
	}
	return (0);
}
