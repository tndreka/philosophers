/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:49:08 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/11 15:52:20 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

long	current_time(void)
{
	struct timeval time;

	if (gettimeofday(&time, NULL) != 0)
	{
		ft_puterr("Error : gettimeofday()", 2);
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void print(t_philo *philo, char *s)
{
	t_secure	data;
	long		timestamp;

	if (philo->dining->finish_routine)
		return;
	data.data1 = &philo->dining->write;
	data.code = MUTEX_LOCK;
	secure_function(&data);
	timestamp = current_time() - philo->dining->start_time;
	printf("%ld %d %s", timestamp, philo->index, s);
	data.code = MUTEX_UNLOCK;
	secure_function(&data);
}