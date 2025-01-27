/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:18:32 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/27 18:52:49 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
		In these utils i am creating safer fornction with returns case in 
		case of an ERRor
		1) Malloc
		2) Mutex
		3)threads
*/

/* ========= MALLOC ======== */
void	*alloc_malloc(size_t byte)
{
	void	*memory;

	memory = malloc(byte);
	if (!memory)
		ft_puterr("Error: Malloc function", 2);
	return (memory);
}

// ============== BLUEPRINT ========== 
int		secure_function(t_secure *data)
{
	int			res;

	res = 0;
	if (data->code == THREAD_CREATE || data->code == THREAD_EXIT || data->code == THREAD_JOIN)
	{
		if (secure_thread((data) == 0) // to do
			return(res);
		else
			ft_puterr("Error: Thread_secure function failed", 2);
	}
	else if (data->code == MUTEX_INIT || data->code == MUTEX_DESTROY || data->code == MUTEX_LOCK || data->code == MUTEX_UNLOCK)
	{
		if (secure_mutex(data) == 0) // to do 
			return(res);
		else
			ft_puterr("Error: secure_mutex function failed", 2);
	}
	return (res);	
}

/* 
============= THREAD CREATE, THREAD_JOIN, THREAD_EXIT ==============
*/

int		secure_thread(t_secure *data)
{
	int res;
	
	if (data->code == THREAD_CREATE)
	{
		res = pthread_create((pthread_t *)data->data1, NULL,(void*(*)(void*))data->data2, data->data3);
		if (0 != res)
		{
			ft_puterr("Error : pthread_create failed", 2);
			return(EXIT_FAILURE);
		}
	}
	else if (data->code == THREAD_JOIN)
	{
		res = pthread_join((pthread_t *)data->data1, (void **)data->data2);
		if (0 != res)
		{
			ft_puterr("Error: pthread_join failed", 2);
			return(EXIT_FAILURE);
		}	
	}
	else if (data->code == THREAD_EXIT)
		pthread_exit(data->data1);
	return(EXIT_SUCCESS);
}

/*
        MUTEX
INIT, DESTROY, LOCK , UNLOCK
*/

int		secure_mutex(t_secure *data)
{
	int res;

	if (data->code == MUTEX_INIT)
		res = pthread_mutex_init((pthread_mutex_t *)data->data1, NULL);
	else if (data->code == MUTEX_DESTROY)
		res = pthread_mutex_destroy((pthread_mutex_t *)data->data1);
	else if (data->code == MUTEX_LOCK)
		res = pthread_mutex_lock((pthread_mutex_t *)data->data1);
	else if (data->code == MUTEX_UNLOCK)
		res = pthread_mutex_unlock((pthread_mutex_t *)data->data1);
	return(EXIT_SUCCESS);
}
