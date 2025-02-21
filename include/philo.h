/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:55 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/21 11:50:38 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*
 ** ====== [INCLUDES] =======
*/

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h> 
# include <stdbool.h>
# include <sys/time.h>
# include <limits.h> 

/*
 ** ======= [STRUCTS] =======
*/

typedef struct s_dining	t_dining;

/*	
	======== [ENUM CODE STRUCT] =========
*/
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

/*
 ** ======== [FORKS] ========
*/
typedef struct e_fork
{
	pthread_mutex_t	fork;
	int				fork_id;
}				t_fork;

/*
 ** ========= [PTHREAD & MUTEX WRAPPER STRUCT]
*/
typedef struct e_secure
{
	void		*data1;
	void		*data2;
	void		*data3;
	t_code		code;	
}		t_secure;

/*
 ** ========== [INDIVIDUAL_PHILOSOPHER STRUCT] ===========
*/
typedef struct s_philo
{
	pthread_t			thread;
	int					index;
	int					meal_count;
	long				last_meal;
	bool				starving; 
	bool				full;
	pthread_mutex_t 	philo_mtx;
	t_fork				*left_fork;
	t_fork				*right_fork;
	t_dining			*dining;
}	t_philo;

/*
 ** ============= [GENERAL_STRUCT] ==============
*/
typedef struct s_dining
{
	int					philo_nbr;
	int					time_to_eat;
	int					time_to_die;
	int					time_to_sleep;
	int					meal_flag;
	long				start_time;
	bool				dead;
	bool				finish_routine;
	bool				synch_ready;
	pthread_mutex_t		meal_lock;
	pthread_mutex_t		write;
	pthread_mutex_t		dead_lock;
	t_fork				*forks;
	t_philo				*philos;
}	t_dining;

/*
 ** ============== [ PROTOTYPES ] =================
*/

/*
 **  ============ [PARSER] ==============
*/
int		arg_checker(int argc, char *argv[]);
int		analyze_args(int ac, char **av);
int		philo_checker(int argc, char *argv[]);

/*
 **  ============= [INITIALIZATION] ================
*/
int		init_dining(t_dining *dining, char *argv[]);
int		initialization_of_struct(t_dining *dining, char *argv[]);
int		assign_data(t_dining *dining);
int		init_mutex_philo(t_dining *dining);
int		create_philo(t_dining *dining);
//void	forks_assign(int i, t_philo *philo, t_fork *forks);

/*
 ** ============= [UTILS] ===============
*/
int		ft_isdigit(char n);
int		ft_atoi(const char *str);
void	ft_puterr(char *s, int fd);
void	*alloc_malloc(size_t byte);
int		secure_function(t_secure *data);
int		secure_thread(t_secure *data);
int		secure_mutex(t_secure *data);
void	print(t_philo *philo, char *s);
int		ft_usleep(size_t milliseconds);
int		death_check(t_dining *dining);
/*
**  ============== [TIME] =============== 
*/

long	current_time(void);

/*
 **  ============= [DINING_ROUTINE] ==============
*/
void	start_dining(t_dining *dining);
void	handle_one_philo(t_dining *dining);
void	philo_thread(t_dining *dining);
void	*dining_routine(void *arg);
void	get_fork(t_philo *philo);
void	let_fork(t_philo *philo);
void	*philo_camera(void *arg);

#endif