/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:01 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/22 10:48:38 by tndreka          ###   ########.fr       */
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
	dining->synch_ready = false;
	dining->dead = false;
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

int	init_mutex_philo(t_dining *dining)
{
	int	i;

	if (pthread_mutex_init(&dining->dead_lock, NULL) != 0)
	{
		ft_puterr("dining_mtx failed", 2);
		return (1);
	}
	if (pthread_mutex_init(&dining->meal_lock, NULL) != 0)
	{
		ft_puterr("dining_mtx failed", 2);
		return (1);
	}
	if (pthread_mutex_init(&dining->write, NULL) != 0)
	{
		ft_puterr("dining_mtx failed", 2);
		return (1);
	}
	i = 0;
	while (i < dining->philo_nbr)
	{
		if (pthread_mutex_init(&dining->forks[i].fork, NULL) != 0)
		{
			ft_puterr("dining_mtx failed", 2);
			break ;
		}
		i++;
	}
	return (0);
}

int	create_philo(t_dining *dining)
{
	t_philo		*philo;
	int			i;

	i = 0;
	while (i < dining->philo_nbr)
	{
		philo = dining->philos + i;
		philo->dining = dining;
		philo->index = i + 1;
		philo->full = false;
		philo->meal_count = 0;
		philo->left_fork = &dining->forks[i];
		philo->right_fork = &dining->forks[(i + 1) % dining->philo_nbr];
		if (pthread_mutex_init(&philo->philo_mtx, NULL) != 0)
		{
			ft_puterr("Error philo_mtx failed", 2);
		}
		i++;
	}
	return (0);
}
