/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:18:32 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/21 11:51:11 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//
void	*alloc_malloc(size_t byte)
{
	void	*memory;

	memory = malloc(byte);
	if (!memory)
	{
		ft_puterr("Error: Malloc function", 2);
	}
	return (memory);
}

int	secure_function(t_secure *data)
{
	int			res;

	res = 0;
	if (data->code == THREAD_CREATE || data->code == THREAD_EXIT
		|| data->code == THREAD_JOIN)
	{
		if (secure_thread(data) == 0)
			return (res);
		else
			ft_puterr("Error: Thread_secure function failed", 2);
	}
	else if (data->code == MUTEX_INIT || data->code == MUTEX_DESTROY
		|| data->code == MUTEX_LOCK || data->code == MUTEX_UNLOCK)
	{
		if (secure_mutex(data) == 0)
			return (res);
		else
			ft_puterr("Error: secure_mutex function failed", 2);
	}
	return (res);
}

int	secure_thread(t_secure *data)
{
	int	res;

	res = 0;
	if (data->code == THREAD_CREATE)
	{
		res = pthread_create((pthread_t *)data->data1, NULL,
				(void *(*)(void *))data->data2, data->data3);
		if (0 != res)
		{
			ft_puterr("Error : pthread_create failed", 2);
			return (EXIT_FAILURE);
		}
	}
	else if (data->code == THREAD_JOIN)
	{
		res = pthread_join(*(pthread_t *)data->data1, NULL);
		if (0 != res)
		{
			ft_puterr("Error: pthread_join failed", 2);
			return (EXIT_FAILURE);
		}
	}
	else if (data->code == THREAD_EXIT)
		pthread_exit(data->data1);
	return (EXIT_SUCCESS);
}

int	secure_mutex(t_secure *data)
{
	int	res;

	res = 0;
	if (data->code == MUTEX_INIT)
		res = pthread_mutex_init((pthread_mutex_t *)data->data1, NULL);
	else if (data->code == MUTEX_DESTROY)
		res = pthread_mutex_destroy((pthread_mutex_t *)data->data1);
	else if (data->code == MUTEX_LOCK)
		res = pthread_mutex_lock((pthread_mutex_t *)data->data1);
	else if (data->code == MUTEX_UNLOCK)
		res = pthread_mutex_unlock((pthread_mutex_t *)data->data1);
	if (res != 0)
	{
		ft_puterr("Error in MUTEX", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
