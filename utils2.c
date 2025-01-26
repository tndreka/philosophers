/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:18:32 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/26 18:56:35 by tndreka          ###   ########.fr       */
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
void	secure_function(t_secure *data)
{
	void **res;
	if (data->code == MALLOC)
	{
		**res = (void **)data->data1;
		*res = alloc_malloc(data->bytes);
	}
}
/*MALLOC*/
void	*alloc_malloc(size_t byte)
{
	void	*memory;

	memory = malloc(byte);
	if (!memory)
		ft_puterr("Error: Malloc function", 2);
	return (memory);
}

/* MUTEX 
	INIT, DESTROY, LOCK, UNLOCK*/

void	secure_mutex(t_philo *philo, t_secure *data)
{
	
}