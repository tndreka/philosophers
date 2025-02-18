/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:49:08 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/18 15:13:12 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

	if (philo->dining->finish_routine)
		return;
	pthread_mutex_lock(&philo->dining->write);
	timestamp = current_time() - philo->dining->start_time;
	if (timestamp < 0)
		ft_puterr("err===> negative TIMEE", 2);
	else 
		printf("%ld %d %s", timestamp, philo->index, s);
	pthread_mutex_unlock(&philo->dining->write);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = current_time();
	while ((current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}