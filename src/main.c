/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:37 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/18 11:10:12 by tndreka          ###   ########.fr       */
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

int main(int ac, char *av[])
{
	t_dining	dining;
	
	if(arg_checker(ac, av) != 0)
		return(EXIT_FAILURE);
	if (init_dining(&dining, av) != 0)
		return(EXIT_FAILURE);
	start_dining(&dining);
	cleanup(&dining);
	return(EXIT_SUCCESS);
}