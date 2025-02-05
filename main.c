/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:37 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/05 18:07:39 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_init_data(t_dining *dining)
{
	printf("======= All the info for Initialization");
	printf("--> Numbers of philosophers: %d\n", dining->philo_nbr);
	printf("Time to die %d\n", dining->time_to_die);
	printf("time to eat %d\n", dining->time_to_eat);
	printf("Time to sleep %d\n", dining->time_to_sleep);
	printf("Number of meals %d\n", dining->meal_flag);
}

int	main(int argc, char **argv)
{
	t_dining	dining;

	if (arg_checker(argc, argv) != 0)
	{
		ft_puterr("Error :  Put the correct arguments for the philo program\n", 2);
		return (EXIT_FAILURE);
	}
	initialization_of_struct(&dining, argv);
	//print_init_data(&dining);
	assign_data(&dining);
	//print_init_data(&dining);
	init_forks_per_philo(&dining);
	//print_init_data(&dining);
	create_philo(&dining);
	//print_init_data(&dining);
	return (EXIT_SUCCESS);
}
