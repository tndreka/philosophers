/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:37 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/12 20:34:15 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dining	dining;

	if (arg_checker(argc, argv) != 0)
	{
		ft_puterr("Error:Put the correct arguments for the philo program\n", 2);
		return (EXIT_FAILURE);
	}
	if (init_dining(&dining, argv) != 0)
	{
		ft_puterr("Error: Inintialization of dining_philo FAILED!!!", 2);
		return (EXIT_FAILURE);
	}
	//initialization_of_struct(&dining, argv);
	//assign_data(&dining);
	//init_mutex_philo(&dining);
	//create_philo(&dining);
	start_dining(&dining);
	return (EXIT_SUCCESS);
}

int init_dining(t_dining *dining, char *argv[])
{
	if (initialization_of_struct(dining, argv) != 0)
	{
		ft_puterr("Error: initialization_of_struct failed !!", 2);
		return (1);
	}
	if (assign_data(dining) != 0)
	{
		ft_puterr("Error: Assign-data failed !!", 2);
		return (1);
	}
	if (init_mutex_philo(dining) != 0)
	{
		ft_puterr("Error: init_mutex_philo failed !!", 2);
		return (1);
	}
	if (create_philo(dining) != 0)
	{
		ft_puterr("Error: create_philo failed !!", 2);
		return (1);
	}
	return (0);
}
