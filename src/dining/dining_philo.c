/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/21 12:55:34 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/*
================================ MONITOR =======================================
*/
void *philo_camera(void *arg)
{
	t_dining *dining;
	long 	timing_last_m;
	int		i;
	
	dining = (t_dining *)arg;

	while (1)
	{
		i = 0;
		while (i < dining->philo_nbr)
		{
			pthread_mutex_lock(&dining->meal_lock);
			timing_last_m =  current_time() - dining->philos[i].last_meal;
			if( timing_last_m > dining->time_to_die)
			{
				print(&dining->philos[i], "died\n");
				dining->finish_routine = true;
				pthread_mutex_unlock(&dining->meal_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&dining->meal_lock);
			i++;
		}
		ft_usleep(1);
	}
	return (NULL);
}
/*
============================== DINING ==========================================
*/
void	start_dining(t_dining *dining)
{
	if (!dining->meal_flag)
		return;
	else if (dining->philo_nbr == 1)
	 	handle_one_philo(dining);
	else
		philo_thread(dining);
}

void	handle_one_philo(t_dining *dining)
{
	dining->start_time = current_time();
	print(&dining->philos[0], "has taken a fork\n");
	ft_usleep(dining->time_to_die);
	print(&dining->philos[0], "died\n");
}

/*
============================ threads_create =======================================================
*/
void	philo_thread(t_dining *dining)
{
	int		i;

	pthread_t			monitor;
	dining->start_time = current_time();
	i = 0;
	while (i < dining->philo_nbr)
	{
		dining->philos[i].last_meal = dining->start_time;
		i++;
	}
	i = 0;
	while (i < dining->philo_nbr)
	{
		if (pthread_create(&dining->philos[i].thread, NULL, dining_routine, &dining->philos[i]) != 0)
			ft_puterr("failed creating the threads\n",2);
		i++;
	}
	dining->synch_ready = true;
	if (pthread_create(&monitor, NULL, philo_camera, dining) != 0)
		ft_puterr("failed creating the monitoring\n", 2);
	pthread_join(monitor, NULL);
	i = 0;
	while (i < dining->philo_nbr)
	{
		pthread_join(dining->philos[i].thread, NULL);
		i++;
	}

}


void	get_fork(t_philo *philo)
{
	if(philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		print(philo, "has taken a fork\n");
		pthread_mutex_lock(&philo->right_fork->fork);
		print(philo, "has taken a fork\n");
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		print(philo, "has taken a fork\n");
		pthread_mutex_lock(&philo->left_fork->fork);
		print(philo, "has taken a fork\n");
	}
}

void	let_fork(t_philo *philo)
{
	if(philo->index % 2 == 0)
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

void	*dining_routine(void *arg)
{
	t_philo  *philo = (t_philo *)arg;

	while (1)
	{
		pthread_mutex_lock(&philo->dining->dead_lock);
		if(philo->dining->finish_routine)
		{
			pthread_mutex_unlock(&philo->dining->dead_lock);
			return(NULL);
		}
		pthread_mutex_unlock(&philo->dining->dead_lock);
		get_fork(philo);
		pthread_mutex_lock(&philo->dining->meal_lock);
		philo->last_meal = current_time();
		philo->meal_count++;
		pthread_mutex_unlock(&philo->dining->meal_lock);
		print(philo, "is eating\n");
		ft_usleep(philo->dining->time_to_eat);
		let_fork(philo);
		
		print(philo, "is sleeping\n");
		ft_usleep(philo->dining->time_to_sleep);
		
		print(philo, "is thinking\n");
	}
	return (NULL);
}
