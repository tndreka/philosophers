/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/13 16:41:05 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dining(t_dining *dining)
{
	//here we start to count the time
	//here we initilize threads per philo[i]
	philo_thread(dining);
	//monitoring =>to do
	//join the threads
	//free cleanup
	// free(dining->philos);
	// 	free(dining->forks);	
}

void philo_thread(t_dining *dining)
{
	t_secure	data;
	int			i;
	if (!dining) {
        printf("Error: dining is NULL\n");
        return;
    }
    if (!dining->philos) {
        printf("Error: dining->philos is NULL\n");
        return;
    }
    if (dining->philo_nbr <= 0) {
        printf("Error: Invalid philosopher count: %d\n", dining->philo_nbr);
        return;
    }

    printf("Dining start time: %ld\n", time_start());

    for (int i = 0; i < dining->philo_nbr; i++) {
        if (&dining->philos[i] == NULL) {
            printf("Error: Philosopher %d is NULL\n", i);
            return;
        }
        printf("Philosopher %d initialized successfully\n", i);
    }
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
			data.data1 = philo->right_fork;
			data.code = MUTEX_LOCK;
			secure_function(&data);
			print(philo, "has taken a fork\n");
			data.data1 = philo->left_fork;
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
