/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:49:08 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/06 18:49:37 by tndreka          ###   ########.fr       */
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
