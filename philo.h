/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:55 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/22 17:23:36 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> // threads liberary 
# include <stdio.h> // printf 
# include <stdlib.h> // malloc & free
# include <unistd.h> // write & sleep
# include <stdbool.h>
# include <sys/time.h> // gettime
# include <limits.h> 

// Struct for the philosophers
typedef struct s_philo
{
	int					id;
	int					last_meal;
	pthread_t			thread;
	pthread_mutex_t		left_fork;
	pthread_mutex_t		right_fork;
}	t_philo;

//General Struct
typedef struct s_dining
{
	int					philo_nbr; // number of philo
	int					time_to_eat; // time to eat
	int					time_to_die; // time to die
	int					time_to_sleep; // time to sleep 
	int					meal_flag;// [if the optional input is there]
	int					start_time; // the time cap when the routine has started
	bool				finish_routine;//when 1philo is-.-||all the philos,eated
	t_philo				*philos;
}	t_dining;

//Argument check functions
int		arg_checker(int ac, char **av);
int		analyze_args(int ac, char **av);

//Utils functions
int		ft_isdigit(char n);
int		ft_atoi(const char *str);
void	ft_puterr(char *s, int fd);

#endif