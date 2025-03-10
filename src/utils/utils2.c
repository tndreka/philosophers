/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:49:08 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/24 18:31:20 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//
long	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) != 0)
	{
		ft_puterr("Error : gettimeofday()", 2);
		return (-1);
	}
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print(t_philo *philo, char *s)
{
	long		timestamp;

	pthread_mutex_lock(&philo->dining->dead_lock);
	if (philo->dining->finish_routine)
	{
		pthread_mutex_unlock(&philo->dining->dead_lock);
		return ;
	}
	pthread_mutex_unlock(&philo->dining->dead_lock);
	pthread_mutex_lock(&philo->dining->write);
	timestamp = current_time() - philo->dining->start_time;
	printf("%ld %d %s\n", timestamp, philo->index, s);
	pthread_mutex_unlock(&philo->dining->write);
}

int	ft_usleep(size_t milliseconds, t_dining *dining)
{
	size_t	start;

	start = current_time();
	while ((current_time() - start) < milliseconds)
	{
		usleep(500);
		pthread_mutex_lock(&dining->dead_lock);
		if (dining->finish_routine)
		{
			pthread_mutex_unlock(&dining->dead_lock);
			return (1);
		}
		pthread_mutex_unlock(&dining->dead_lock);
	}
	return (0);
}
