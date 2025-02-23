/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:07:14 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/23 21:13:21 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	*philo_camera(void *arg)
// {
// 	t_dining	*dining;
// 	long		timing_last_m;
// 	int			i;
// 	int			full;

// 	dining = (t_dining *)arg;
// 	while (1)
// 	{
// 		full = 0;
// 		i = 0;
// 		while (i < dining->philo_nbr)
// 		{
// 			pthread_mutex_lock(&dining->meal_lock);
// 			timing_last_m = current_time() - dining->philos[i].last_meal;
// 			pthread_mutex_unlock(&dining->meal_lock);
// 			if (timing_last_m > dining->time_to_die)
// 			{
// 				print(&dining->philos[i], "died\n");
// 				pthread_mutex_lock(&dining->dead_lock);
// 				dining->finish_routine = true;
// 				pthread_mutex_unlock(&dining->dead_lock);
// 				return (NULL);
// 			}
// 			pthread_mutex_lock(&dining->meal_lock);
// 			if (dining->meal_flag != -1
// 				&& dining->philos[i].meal_count >= dining->meal_flag)
// 				full++;
// 			pthread_mutex_unlock(&dining->meal_lock);
// 			i++;
// 		}
// 		if (full == dining->philo_nbr)
// 		{
// 			pthread_mutex_lock(&dining->dead_lock);
// 			dining->finish_routine = true;
// 			pthread_mutex_unlock(&dining->dead_lock);
// 			return (NULL);
// 		}
// 		usleep(200);
// 	}
// 	return (NULL);
// }

void	*philo_camera(void *arg)
{
	t_dining	*dining;
	int			i;
	int			full;

	dining = (t_dining *)arg;
	while (1)
	{
		full = 0;
		i = -1;
		pthread_mutex_lock(&dining->meal_lock);
		while (++i < dining->philo_nbr)
		{
			if (check_philo_dead(dining, i))
			{
				pthread_mutex_unlock(&dining->meal_lock);		
				return (NULL);
			}
			// pthread_mutex_lock(&dining->meal_lock);
			if (dining->meal_flag != -1 && dining->philos[i].meal_count >= dining->meal_flag)
				full++;
			// pthread_mutex_unlock(&dining->meal_lock);
			// if (dining->meal_flag != -1 && full == dining->philo_nbr)
			// 	break ;
		}
		if (dining->meal_flag != -1 && full == dining->philo_nbr)
		{
			pthread_mutex_lock(&dining->dead_lock);
			dining->finish_routine = true;
			pthread_mutex_unlock(&dining->dead_lock);
			pthread_mutex_unlock(&dining->meal_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&dining->meal_lock);
		usleep(1000);
	}
	return (NULL);
}

bool	check_philo_dead(t_dining *dining, int i)
{
	long long	timing_last_m;

	// pthread_mutex_lock(&dining->meal_lock);
	timing_last_m = current_time() - dining->philos[i].last_meal;
	// pthread_mutex_unlock(&dining->meal_lock);
	if (timing_last_m > dining->time_to_die)
	{
		print(&dining->philos[i], "died\n");
		pthread_mutex_lock(&dining->dead_lock);
		dining->finish_routine = true;
		pthread_mutex_unlock(&dining->dead_lock);
		return (true);
	}
	return (false);
}

// void	meal_flag(t_dining *dining)
// {
// 	int		i;
// 	int		all_eat;

// 	if (dining->meal_flag != -1)
// 	{
// 		all_eat = 1;
// 		pthread_mutex_lock(&dining->meal_lock);
// 		i = -1;
// 		while (++i < dining->philo_nbr)
// 		{
// 			if (dining->philos[i].meal_count < dining->meal_flag)
// 			{
// 				all_eat = 0;
// 				break ;
// 			}
// 		}
// 		if (all_eat)
// 		{
// 			pthread_mutex_lock(&dining->dead_lock);
// 			dining->finish_routine = true;
// 			pthread_mutex_unlock(&dining->dead_lock);
// 			// i = -1;
// 			// while (++i < dining->philo_nbr)
// 			// 	printf("Philosopher %d ate %d times\n", dining->philos[i].index, dining->philos[i].meal_count);
// 			return ;
// 		}
// 		pthread_mutex_unlock(&dining->meal_lock);
// 	}
// }
