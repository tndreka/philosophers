/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:49:08 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/21 11:56:00 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//
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
	long		timestamp;

	pthread_mutex_lock(&philo->dining->write);
	if (philo->dining->finish_routine)
	{
		pthread_mutex_unlock(&philo->dining->write);
		return;
	}
	timestamp = current_time() - philo->dining->start_time;
	printf("%ld %d %s", timestamp, philo->index, s);
	pthread_mutex_unlock(&philo->dining->write);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = current_time();
	while ((current_time() - start) < milliseconds)
		usleep(milliseconds / 10);
	return (0);
}