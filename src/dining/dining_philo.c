/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/17 20:16:48 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void  handle_one_philo(t_dining *dining);

void	start_dining(t_dining *dining)
{
	if (!dining->meal_flag)
		return;
	// else if (dining->philo_nbr == 1)
	// 	handle_one_philo(dining);
	else
		philo_thread(dining);
}


static void even_odd(t_philo *philo)
{
	t_secure data;

	if(philo->index % 2 == 0)
	{
		//Takes both fork left&right
		data.data1 = philo->left_fork;
		data.code = MUTEX_LOCK;
		secure_function(&data);
		print(philo, "has taken a fork\n");
		
		data.data1 = philo->right_fork;
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
	t_philo		*philo;
	t_secure	data;

	philo = (t_philo *)arg;

	// synch_thread(philo->dining);
	while (!philo->dining->finish_routine)
	{
		if(philo->full)
			break ;
		even_odd(philo);
		print(philo, "is eating\n");
		philo->meal_count++;
		ft_usleep(philo->dining->time_to_eat);
		if(philo->index % 2 == 0)
		{
			data.data1 = philo->right_fork;
			data.code = MUTEX_UNLOCK;
			secure_function(&data);
			data.data1 = philo->left_fork;
			data.code = MUTEX_UNLOCK;
			secure_function(&data);
		}
		else
		{
			data.data1 = philo->right_fork;
			data.code = MUTEX_UNLOCK;
			secure_function(&data);
			data.data1 = philo->left_fork;
			data.code = MUTEX_UNLOCK;
			secure_function(&data);
		}
		print(philo, "is sleeping\n");
		ft_usleep(philo->dining->time_to_sleep);	
		
	}
	
	return(NULL);	
}


// void	*dining_routine(void *arg)
// {
// 	t_philo 	*philo;
// 	t_secure	data;
// 	philo = (t_philo *)arg;
// 	while (!philo->dining->finish_routine)
// 	{
// 		if(philo->index % 2 == 0)
// 		{
// 			//Takes both fork left&right
// 			data.data1 = philo->left_fork;
// 			data.code = MUTEX_LOCK;
// 			secure_function(&data);
// 			print(philo, "has taken a fork\n");
			
// 			data.data1 = philo->right_fork;
// 			data.code = MUTEX_LOCK;
// 			secure_function(&data);
// 			print(philo, "has taken a fork\n");
// 		}
// 		else
// 		{
// 			data.data1 = philo->right_fork;
// 			data.code = MUTEX_LOCK;
// 			secure_function(&data);
// 			print(philo, "has taken a fork\n");
			
// 			data.data1 = philo->left_fork;
// 			data.code = MUTEX_LOCK;
// 			secure_function(&data);
// 			print(philo, "has taken a fork\n");
// 		}
// 		//EAT
// 		print(philo, "is eating\n");
// 		ft_usleep(philo->dining->time_to_eat);
// 		//usleep(philo->dining->time_to_eat * 1000);
// 		philo->last_meal = current_time();
// 		philo->meal_count++;
// 		if(philo->index % 2 == 0)
// 		{
// 			data.data1 = philo->right_fork;
// 			data.code = MUTEX_UNLOCK;
// 			secure_function(&data);
// 			data.data1 = philo->left_fork;
// 			data.code = MUTEX_UNLOCK;
// 			secure_function(&data);
// 		}
// 		else
// 		{
// 			data.data1 = philo->right_fork;
// 			data.code = MUTEX_UNLOCK;
// 			secure_function(&data);
// 			data.data1 = philo->left_fork;
// 			data.code = MUTEX_UNLOCK;
// 			secure_function(&data);
// 		}
		
// 		//sleep
// 		print(philo, "is sleeping\n");
// 		ft_usleep(philo->dining->time_to_sleep); 
//         //usleep(philo->dining->time_to_sleep * 1000);
        
// 		print(philo, "is thinking\n");
		
// 	}
// 	return (NULL);
// }
