/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka < tndreka@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:31:18 by tndreka           #+#    #+#             */
/*   Updated: 2025/02/24 18:27:47 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_checker(int argc, char *argv[])
{
	if (argc == 5 || argc == 6)
		return (philo_checker(argc, argv));
	else
		return (ft_puterr("Error: Invalid number of arguments\n", 2), 1);
}

int	philo_checker(int argc, char *argv[])
{
	if (!analyze_args(argc, argv))
	{
		ft_puterr("Error: Arguments should be an INT\n", 2);
		return (1);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
	{
		ft_puterr("Error: Number of philosophers should be between 1 \
		and 200\n", 2);
		return (1);
	}
	if (ft_atoi(argv[2]) < 60 || ft_atoi(argv[3]) < 60 || ft_atoi(argv[4]) < 60)
	{
		ft_puterr("Error: Time to eat, time to die and time to sleep should \
				be at least 60\n", 2);
		return (1);
	}
	if (argc == 6 && ft_atoi(argv[5]) < 1)
	{
		ft_puterr("Error: Number of meals should be at least 1\n", 2);
		return (1);
	}
	return (0);
}

int	analyze_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) != 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
