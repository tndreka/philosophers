/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/10 20:03:21 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dining(t_dining *dining)
{
	//here we start to count the time
	dining->start_time = time_start();
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

	i = 0;
	
	while (i < dining->philo_nbr)
	{
		data.data1 = &dining->philos[i].thread;
		data.data2 = dining_routine;
		data.data3 = &dining->philos[i];
		data.code = THREAD_CREATE;
		secure_function(&data);
		i++;
	}	
}

void	*dining_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if(philo->index % 2 == 0)
		{
			//here take the forks and mutex lock for left and right
			//print the action
		}
		else
		{
			////here take the forks and mutex lock for left and right
		}
		// now i should have the print that the philo is eating keep a count at 
		//last time that he eated and also ad the count on the meal eated 
	}
	return (NULL);
}
