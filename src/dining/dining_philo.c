/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/13 19:30:43 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void dining_monitoring(void *arg);

void	start_dining(t_dining *dining)
{
	philo_thread(dining);
}

void philo_thread(t_dining *dining)
{
	t_secure	data;
	int			i;

	i = 0;
	dining->start_time = time_start();
	while (i < dining->philo_nbr)
	{
		dining->philos[i].last_meal = dining->start_time;
		i++;	
	}
	i = 0;
	while (i < dining->philo_nbr)
	{
		printf("failed on creatin the thread -->addres %p", &dining->philos[i]);
		data.data1 = &dining->philos[i].thread;
		data.data2 = dining_routine;
		data.data3 = &dining->philos[i];
		data.code = THREAD_CREATE;
		if(secure_function(&data)!= 0)
			printf("failed on creatin the thread %d", i);
		i++;
	}
	data.data1 = &dining->monitor_thread;
	data.data2 = dining_monitoring;
	data.data3 = dining;
	data.code  = THREAD_CREATE;
	if(secure_function(&data) != 0)
		ft_puterr("MONITORING FAILD", 2);
	data.data1 =  &dining->monitor_thread;
	data.code = THREAD_JOIN;
	if(secure_function(&data) != 0)
		ft_puterr("MONITORING FAILD", 2);
	i = 0;
	while (i < dining->philo_nbr)
	{
		data.data1 = &dining->philos[i].thread;
		data.code = THREAD_JOIN;
		secure_function(&data);
		i++;
	}
}

void	*dining_routine(void *arg)
{
	t_philo 	*philo;
	t_secure	data;
	philo = (t_philo *)arg;
	while (!philo->dining->finish_routine)
	{
		if(philo->index % 2 == 0)
		{
			data.data1 = philo->right_fork;
			data.code = MUTEX_LOCK;
			secure_function(&data);
			print(philo, "has taken a fork\n");
			data.data1 = philo->left_fork;
			data.code = MUTEX_LOCK;
			secure_function(&data);
			print(philo, "has taken a fork\n");
		}
		else
		{
			data.data1 = philo->left_fork;
			data.code = MUTEX_LOCK;
			secure_function(&data);
			print(philo, "has taken a fork\n");
			data.data1 = philo->right_fork;
			data.code = MUTEX_LOCK;
			secure_function(&data);
			print(philo, "has taken a fork\n");
		}
		print(philo, "is eating\n");
		usleep(philo->dining->time_to_eat * 1000);
		philo->last_meal = current_time();
		philo->meal_count++;
		data.data1 = philo->right_fork;
		data.code = MUTEX_UNLOCK;
		secure_function(&data);
		data.data1 = philo->left_fork;
		data.code = MUTEX_UNLOCK;
		secure_function(&data);
		print(philo, "is sleeping\n");
        usleep(philo->dining->time_to_sleep * 1000); 
        print(philo, "is thinking\n");
		
	}
	return (NULL);
}
