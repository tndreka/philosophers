/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/24 19:16:11 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
	// i = 0;
	// while (i < dining->philo_nbr)
	// {
	// 	printf("Philosopher %d ate %d times\n",
	// 		dining->philos[i].index,
	// 		dining->philos[i].meal_count);
	// 	i++;
	// }

void	start_dining(t_dining *dining)
{
	if (!dining->meal_flag)
		return ;
	else if (dining->philo_nbr == 1)
		handle_one_philo(dining);
	else
		philo_thread(dining);
}

void	handle_one_philo(t_dining *dining)
{
	dining->start_time = current_time();
	print(&dining->philos[0], "has taken a fork");
	ft_usleep(dining->time_to_die, dining);
	print(&dining->philos[0], "died");
}

void	philo_thread(t_dining *dining)
{
	int				i;
	pthread_t		monitor;

	dining->start_time = current_time();
	i = -1;
	while (++i < dining->philo_nbr)
		dining->philos[i].last_meal = dining->start_time;
	i = 0;
	while (i < dining->philo_nbr)
	{
		if (pthread_create(&dining->philos[i].thread, NULL, dining_routine,
				&dining->philos[i]) != 0)
			ft_puterr("failed creating the threads\n", 2);
		i++;
	}
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

void	*dining_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->index % 2 == 0)
		usleep(100);
	while (1)
	{
		print(philo, "is thinking");
		if (terminate_dining(philo))
			return (NULL);
		eat(philo);
		if (terminate_dining(philo))
			return (NULL);
		print(philo, "is sleeping");
		ft_usleep(philo->dining->time_to_sleep, philo->dining);
	}
	return (NULL);
}

bool	terminate_dining(t_philo *philo)
{
	bool	should_stop;

	pthread_mutex_lock(&philo->dining->dead_lock);
	should_stop = philo->dining->finish_routine || philo->full;
	pthread_mutex_unlock(&philo->dining->dead_lock);
	return (should_stop);
}
