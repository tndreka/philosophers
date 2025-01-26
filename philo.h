/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:55 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/26 18:16:06 by tndreka          ###   ########.fr       */
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

// Struct for type of Codes that will be in this program
typedef enum type_code
{
	MALLOC,
	THREAD_CREATE,
	THREAD_EXIT,
	THREAD_JOIN,
	MUTEX_INIT,
	MUTEX_DESTROY,
	MUTEX_LOCK,
	MUTEX_UNLOCK
}			t_code;
// Struct for the philosophers

typedef struct e_secure
{
	size_t		bytes;
	void		*data1;
	void		*data2;
	t_code		code;	
}		t_secure;
typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					meal_count;
	int					last_meal;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
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
int		arg_checker(int argc, char *argv[]);
int		analyze_args(int ac, char **av);
int		philo_checker(int argc, char *argv[]);

//Initialization functions
void	initialization(t_dining *dining, int argc, char *argv[]);

//Utils functions
int		ft_isdigit(char n);
int		ft_atoi(const char *str);
void	ft_puterr(char *s, int fd);

#endif