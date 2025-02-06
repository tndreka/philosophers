/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:25:02 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/06 17:44:24 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dining(t_dining *dining)
{
	//here we start to count the tim
	time_start();
	//here we initilize threads per philo[i]
	create_threads(dining);
}

long	time_start(void)
{
	struct timeval	tv;
	long			milisec;

	if (gettimeofday(&tv, NULL) == 0)
	{
		milisec = (tv.tv_sec * 1000L) + (tv.tv_usec / 1000L);
		return (milisec);
	}
	return (-1);
}
