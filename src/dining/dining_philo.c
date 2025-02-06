/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/06 19:39:56 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dining(t_dining *dining)
{
	printf("started diningg \n");
	//here we start to count the time
	dining->start_time = time_start();
	//here we initilize threads per philo[i]
	printf("threads_creating \n");
	philo_thread(dining);
	printf("creating====> check √ \n");
	//monitoring =>to do
	
}

void philo_thread(t_dining *dining)
{
	t_secure	data;
	int			i;

	i = 0;
	
	while (i < dining->philo_nbr)
	{
		data.data1 = &dining->philos[i].thread;
		data.data2 = dining_routine;
		data.data3 = &dining->philos[i];
		data.code = THREAD_CREATE;
		secure_function(&data);
		printf("thread %d is created", i);
		i++;
	}
}

void	*dining_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!philo->dining->finish_routine)
	{
		printf("philo [%d]", philo->index);
		usleep(100);
	}
	return (NULL);
}
