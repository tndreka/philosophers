/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:28:01 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/13 16:38:51 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
/*
				INITIALIZATION
	On this file we are feeding the struct with all the nescesary data that 
	we need for our program to start.
	
*/

/*
		on this part I parse the arguments in to my main struct
*/
// void	initialization_of_struct(t_dining *dining, char *argv[])
// {
// 	dining->philo_nbr = ft_atoi(argv[1]);
// 	dining->time_to_die = ft_atoi(argv[2]);
// 	dining->time_to_eat = ft_atoi(argv[3]);
// 	dining->time_to_sleep = ft_atoi(argv[4]);
// 	if (!argv[5])
// 		dining->meal_flag = -1;
// 	else
// 		dining->meal_flag = ft_atoi(argv[5]);
// 	dining->finish_routine = false;
// }

int initialization_of_struct(t_dining *dining, char *argv[])
{
	if (!argv)
		return (1);
	dining->philo_nbr = ft_atoi(argv[1]);
	dining->time_to_die = ft_atoi(argv[2]);
	dining->time_to_eat = ft_atoi(argv[3]);
	dining->time_to_sleep = ft_atoi(argv[4]);
	if (!argv[5])
		dining->meal_flag = -1;
	else
		dining->meal_flag = ft_atoi(argv[5]);
	return (0);
}

/*
	This functions is created to Allocate memory for the philosopher
	and forks.
	==> Allocated memory for [N] philosophers 
	==> allocated memory for [N] forks per philosopher
*/
int	assign_data(t_dining *dining)
{
	if (dining->philo_nbr <= 0)
	dining->philos =alloc_malloc(sizeof(t_philo)
			* dining->philo_nbr);
	if (!dining->philos)
	{
		ft_puterr("Error: Alloc_malloc-> dining->philos!!",2);
		return(1);
	}
	dining->forks = alloc_malloc (sizeof(t_fork) * dining->philo_nbr);
	if (!dining->forks)
	{
		free(dining->philos);
		dining->philos = NULL;
		ft_puterr("Error: Alloc_malloc-> dining->forks!!",2);
		return(1);
	}
	return(0);
}

/*
		On this function i initialize the mutex for forks for [N]philos
		and if any error happens in the initialization part i destroy the mutex
*/
int	init_mutex_philo(t_dining *dining)
{
	t_secure	data;
	int			i;
	int			j;

	i = 0;
	j = 0;
	// if (!dining->forks)
	// 	return (1);
	data.data1 = &dining->write;
	data.code = MUTEX_INIT;
	if (secure_function(&data) != 0)
		return(EXIT_FAILURE);
	while (i < dining->philo_nbr)
	{
		data.data1 = &dining->forks[i].fork;
		data.code = MUTEX_INIT;
		if (secure_function(&data) != 0)
		{
			data.data1 = &dining->write;
			data.code = MUTEX_DESTROY;
			secure_function(&data);
			while (j > i)
			{
				data.data1 = &dining->forks[i].fork;
				data.code = MUTEX_DESTROY;
				secure_function(&data);
				i--;
			}
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (0);
}

/*
	here i am initializin the individual philospoher struct with all the 
	nescesary data. 
*/
int		create_philo(t_dining *dining)
{
	t_philo	*philo;
	int		i;

	if (!dining || !dining->philos || !dining->forks || dining->philo_nbr <= 0)
		return(1);
	i = 0;
	while (i < dining->philo_nbr)
	{
		philo = dining->philos + i;
		philo->index = i + 1;
		philo->meal_count = 0;
		philo->full = false;
		philo->dining = dining;
		philo->left_fork = &dining->forks[i];
		philo->right_fork = &dining->forks[(i + 1) % dining->philo_nbr];
		// forks_assign(i, philo, dining->forks);
		i++;
	}
	return(0);
}

/*
	in this function i will link each fork to the philosopher.
philo_position = philo_id - 1 (if we start by right)
=>right_fork its going to assigned by the philosopher array by the position
=>left_fork we are starting by
[the position_of_philo + 1(bc is left_fork) % philo_num]
philosopher[0, 1, 2, 3, 4] => this means that we have 5 philos
the right_f[1, 2, 3, 4, 5] => each philo has one fork.
now corresponding to this we will assign
the left forks to the philos by the formula:
[the position_of_philo + 1(bc is left_fork) % philo_num]
 left_fork = (4 + 1) % 5(if we have 5 filos)
 		   =    5  %  5
reminder = 0. => so the 5th philosopher if he will eat 
will get the fork with 0 num assignd.
==> DEADLOCK Soulution -> to prevent this program 
from encountering a deadlock in the
executing part we needed to make sure that each philosopher takes the forks
in proper way,As we now that each philo to eat should have to forks so he 
would be able to eat. in this case 
i founded the soulution of eaven and odd number of philo,
depending on the number of the philosphers
i make the assingment of the left and the right fork.
*/

//===function for forks===
// void	forks_assign(int i, t_philo *philo, t_fork *forks)
// {
// 	// printf("before->forks get_assign\n");
// 	if ((i) % 2)
// 	{
// 		philo->right_fork = &forks[(i)];
// 		philo->left_fork = &forks[(philo->dining->philo_nbr + 1)];
// 	}
// 	else
// 	{
// 		philo->right_fork = &forks[(philo->dining->philo_nbr + 1)];
// 		philo->left_fork = &forks[(i)];
// 	}
// 	// printf("\n");
// 	// printf("after forks get assign\n");
// }
