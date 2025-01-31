/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:55 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/31 18:04:23 by tndreka          ###   ########.fr       */
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

typedef struct e_fork
{
	pthread_mutex_t fork;
	int				fork_id;
}				t_fork;

typedef struct e_secure
{
	void		*data1;
	void		*data2;
	void		*data3;
	t_code		code;	
}		t_secure;
// Struct for the philosophers
typedef struct s_philo
{
	pthread_t			thread; // each philo is a thread
	int					id; 
	int					meal_count; // how many meals has he eated
	int					last_meal; // time passed since eating the last meal
	bool				starving; // if he didnt eat 
	bool				full;  
	t_fork				*left_fork;
	t_fork				*right_fork;
	t_dining			*dining;
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
	t_fork				*forks;
	t_philo				*philos;
}	t_dining;


//Argument check functions
int		arg_checker(int argc, char *argv[]);
int		analyze_args(int ac, char **av);
int		philo_checker(int argc, char *argv[]);

//Initialization functions
void	initialization_of_struct(t_dining *dining, int argc, char *argv[]);

//Utils-1 functions
int		ft_isdigit(char n);
int		ft_atoi(const char *str);
void	ft_puterr(char *s, int fd);

//Utils-2
void	*alloc_malloc(size_t byte);
int		secure_function(t_secure *data);
int		secure_thread(t_secure *data);
int		secure_mutex(t_secure *data);

#endif