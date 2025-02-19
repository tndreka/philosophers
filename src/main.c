/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:37 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/19 12:41:37 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	main(int argc, char **argv)
// {
// 	t_dining	dining;

// 	if (arg_checker(argc, argv) != 0)
// 	{
// 		ft_puterr("Error:Put the correct arguments for the philo program\n", 2);
// 		return (EXIT_FAILURE);
// 	}
// 	if (init_dining(&dining, argv) != 0)
// 	{
// 		ft_puterr("Error: Inintialization of dining_philo FAILED!!!", 2);
// 		return (EXIT_FAILURE);
// 	}
// 	start_dining(&dining);
// 	return (EXIT_SUCCESS);
// }
/*
	new version without wrapper functions 
*/

void cleanup(t_dining *dining)
{
	free(dining->philos);
	free(dining->forks);
}

void ft_exit(t_dining *dining)
{
	int		i;

	i = 0;
	while (i < dining->philo_nbr)
	{
		pthread_mutex_destroy(&dining->forks[i].fork);
		i++;
	}
	pthread_mutex_destroy(&dining->write);
	pthread_mutex_destroy(&dining->meal_lock);
	cleanup(dining);
}

int main(int ac, char *av[])
{
	t_dining	dining;
	
	if(arg_checker(ac, av) != 0)
		return(EXIT_FAILURE);
	if (init_dining(&dining, av) != 0)
		return(EXIT_FAILURE);
	start_dining(&dining);
	ft_exit(&dining);
	return(EXIT_SUCCESS);
}

/*
====== TEST CASES ======
- 1) 1 800 200 200 ->philo should not eat , and should die. √
- 2) 5 800 200 200 -> No philo should die. √
- 3) 5 800 200 200 7 -> the dining will end after the philos eat 7 times --> X || to do || 
- 4) 4 410 200 200 -> No philo should die. √
- 5) 4 310 200 200 -> 1 philo should die. √
- 6) test with 2 philo < 10ms --> X 
- 7) test < 200 --> X 
======================= to check -> sync for eat, sleep , think
*/