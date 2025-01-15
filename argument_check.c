/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:35:32 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/15 18:59:20 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int arg_checker(int ac, char **av)
{
    if (!analyze_args(ac, av))
    {
        printf("The parameters that you have puted are not correct!\n");
        return (1);
    }
    if (ac < 5 || ac > 6)
    {
       printf("You should give these paramaters in the following order: ");
       printf("number_of_philosophers, time_to_die, time_to_eat, time_to_sleep \
       [number_of_times_each_philo_must_eat]\n");
    }
    if(ft_atoi(av[1]) < 1 || ft_atoi(av[1]) > 200)
    {
        printf("The number of philosophers should be at least 1 and max 200\n");
        return (1);
    }
    if (ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60 || ft_atoi(av[4]) < 60)
    {
        printf("The time to die, eat and sleep should be at least 60\n");
        return (1);
    }
    return (0);
}