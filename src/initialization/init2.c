/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:19:09 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/23 16:20:07 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo_mutex(t_dining *dining)
{
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
	return (0);
}

int	init_mutex_philo(t_dining *dining)
{
	int	i;

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
