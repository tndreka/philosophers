/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:37 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/11 15:51:10 by tndreka          ###   ########.fr       */
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
	initialization_of_struct(&dining, argv);
	assign_data(&dining);
	init_mutex_philo(&dining);
	create_philo(&dining);
	start_dining(&dining);
	return (EXIT_SUCCESS);
}
