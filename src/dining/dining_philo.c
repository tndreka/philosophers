/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/19 17:15:40 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static void  handle_one_philo(t_dining *dining);

// void	start_dining(t_dining *dining)
// {
// 	if (!dining->meal_flag)
// 		return;
// 	// else if (dining->philo_nbr == 1)
// 	// 	handle_one_philo(dining);
// 	else
// 		philo_thread(dining);
// }


// static void even_odd(t_philo *philo)
// {
// 	t_secure data;

// 	if(philo->index % 2 == 0)
// 	{
// 		//Takes both fork left&right
// 		data.data1 = philo->left_fork;
// 		data.code = MUTEX_LOCK;
// 		secure_function(&data);
// 		print(philo, "has taken a fork\n");
		
// 		data.data1 = philo->right_fork;
// 		data.code = MUTEX_LOCK;
// 		secure_function(&data);
// 		print(philo, "has taken a fork\n");
// 	}
// 	else
// 	{
// 		data.data1 = philo->right_fork;
// 		data.code = MUTEX_LOCK;
// 		secure_function(&data);
// 		print(philo, "has taken a fork\n");

// 		data.data1 = philo->left_fork;
// 		data.code = MUTEX_LOCK;
// 		secure_function(&data);
// 		print(philo, "has taken a fork\n");
	
// 	}
// }

// void philo_thread(t_dining *dining)
// {
// 	t_secure	data;
// 	int			i;

// 	i = 0;
// 	dining->start_time = time_start();
// 	while (i < dining->philo_nbr)
// 	{
// 		dining->philos[i].last_meal = dining->start_time;
// 		i++;	
// 	}
// 	i = 0;
// 	while (i < dining->philo_nbr)
// 	{
// 		data.data1 = &dining->philos[i].thread;
// 		data.data2 = dining_routine;
// 		data.data3 = &dining->philos[i];
// 		data.code = THREAD_CREATE;
// 		if(secure_function(&data)!= 0)
// 			printf("failed on creatin the thread %d", i);
// 		i++;
// 	}
	
// 	i = 0;
// 	while (i < dining->philo_nbr)
// 	{
// 		data.data1 = &dining->philos[i].thread;
// 		data.code = THREAD_JOIN;
// 		secure_function(&data);
// 		i++;
// 	}
// }

// void	*dining_routine(void *arg)
// {
// 	t_philo		*philo;
// 	t_secure	data;

// 	philo = (t_philo *)arg;

// 	// synch_thread(philo->dining);
// 	while (!philo->dining->finish_routine)
// 	{
// 		if(philo->full)
// 			break ;
// 		even_odd(philo);
// 		print(philo, "is eating\n");
// 		philo->meal_count++;
// 		ft_usleep(philo->dining->time_to_eat);
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
// 		print(philo, "is sleeping\n");
// 		ft_usleep(philo->dining->time_to_sleep);	
		
// 	}
	
// 	return(NULL);	
// }


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


/*
================================================================================
*/

//new verssion without the wrapper

/*
================================ MONITOR =======================================
*/
void *philo_camera(void *arg)
{
	t_dining *dining;

	dining = (t_dining *)arg;
	
	long 	timing_last_m;
	int		i;

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
/*
============================ forks ====================
*/
void	get_fork(t_philo *philo)
{
	if(philo->index % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->fork);
		print(philo, "has taken left fork\n");
		pthread_mutex_lock(&philo->right_fork->fork);
		print(philo, "has taken right fork\n");
	}
	else
	{
		pthread_mutex_lock(&philo->right_fork->fork);
		print(philo, "has taken right  fork\n");
		pthread_mutex_lock(&philo->left_fork->fork);
		print(philo, "has taken left fork\n");
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
/*
 ==========================================================
*/
// void	*dining_routine(void *arg)
// {
// 	t_philo  *philo = (t_philo *)arg;

// 	while (!philo->dining->synch_ready)
//         usleep(100);
// 	while (!philo->dining->finish_routine)
//     {
// 		get_fork(philo);
// 		pthread_mutex_lock(&philo->dining->meal_lock);
// 		philo->last_meal = current_time();
// 		philo->meal_count++;
// 		pthread_mutex_unlock(&philo->dining->meal_lock);
// 		print(philo, "is eating\n");
// 		ft_usleep(philo->dining->time_to_eat);
// 		let_fork(philo);
// 		print(philo, "is sleeping\n");
// 		ft_usleep(philo->dining->time_to_sleep);
// 		print(philo, "is thinking\n");
// 	}
// 	return (NULL);
// }


void	*dining_routine(void *arg)
{
	t_philo 	*philo;
	
	philo = (t_philo *)arg;
	// if(philo->index % 2 == 0)
	// 	ft_usleep(philo->dining->time_to_eat / 2);
	while (!philo->dining->finish_routine)
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
		//EAT
		print(philo, "is eating\n");
		ft_usleep(philo->dining->time_to_eat);
		philo->last_meal = current_time();
		philo->meal_count++;
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
		
		print(philo, "is sleeping\n");
		ft_usleep(philo->dining->time_to_sleep);         
		print(philo, "is thinking\n");
	}
	return (NULL);
}
