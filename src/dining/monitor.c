/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:07:14 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/24 18:58:57 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_camera(void *arg)
{
	t_dining	*dining;
	int			i;
	int			full;

	dining = (t_dining *)arg;
	while (!dining->finish_routine && !full)
	{
		full = 0;
		i = -1;
		pthread_mutex_lock(&dining->meal_lock);
		if (check_status(dining, &full))
		{
			pthread_mutex_unlock(&dining->meal_lock);
			return (NULL);
		}
		is_full(dining, &full);
		pthread_mutex_unlock(&dining->meal_lock);
		usleep(1000);
	}
	return (NULL);
}

void	is_full(t_dining *dining, int *full)
{
	if (dining->meal_flag != -1 && *full == dining->philo_nbr)
	{
		pthread_mutex_lock(&dining->dead_lock);
		dining->finish_routine = true;
		dining->stopped_by_quota = true;
		pthread_mutex_unlock(&dining->dead_lock);
		pthread_mutex_unlock(&dining->meal_lock);
		return ;
	}
}

bool	check_philo_dead(t_dining *dining, int i)
{
	long long	diff;

	diff = current_time() - dining->philos[i].last_meal;
	if (diff > dining->time_to_die)
	{
		print(&dining->philos[i], "died\n");
		pthread_mutex_lock(&dining->dead_lock);
		dining->finish_routine = true;
		pthread_mutex_unlock(&dining->dead_lock);
		return (true);
	}
	return (false);
}

bool	check_status(t_dining *dining, int *full)
{
	int			i;

	i = -1;
	while (++i < dining->philo_nbr)
	{
		if (check_philo_dead(dining, i))
			return (true);
		if (dining->meal_flag != -1
			&& dining->philos[i].meal_count >= dining->meal_flag)
			(*full)++;
	}
	return (false);
}
