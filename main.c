/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:37 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/29 11:38:33 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_dining	dining;

	arg_checker(argc, argv);
	initialization(&dining, argc, argv);
	data_assign(&dining);
	create_philos(&dining);
	return (0);
}
