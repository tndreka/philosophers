/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:05:00 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/23 16:38:38 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->fork);
		print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		print(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->fork);
		print(philo, "has taken a fork");
	}
}

void	let_fork(t_philo *philo)
{
	if (philo->index % 2 == 0)
	{
		pthread_mutex_unlock(&philo->right_fork->fork);
		pthread_mutex_unlock(&philo->left_fork->fork);
	}
	else
	{
		pthread_mutex_unlock(&philo->left_fork->fork);
		pthread_mutex_unlock(&philo->right_fork->fork);
	}
}

void	eat( t_philo *philo)
{
	get_fork(philo);
	pthread_mutex_lock(&philo->dining->meal_lock);
	philo->last_meal = current_time();
	philo->meal_count++;
	pthread_mutex_unlock(&philo->dining->meal_lock);
	print(philo, "is eating");
	ft_usleep(philo->dining->time_to_eat);
	let_fork(philo);
	pthread_mutex_lock(&philo->dining->meal_lock);
	if (philo->meal_count >= philo->dining->meal_flag
		&& philo->dining->meal_flag != -1)
	{
		pthread_mutex_unlock(&philo->dining->meal_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->dining->meal_lock);
}
