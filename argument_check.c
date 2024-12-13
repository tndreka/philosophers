/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:35:32 by tndreka           #+#    #+#             */
/*   Updated: 2024/12/13 01:47:32 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int arg_checker(int ac, char **av)
{
    (void)av;
    if(ac == 1)
    {
        printf("You need to give 4 more parameters: "); 
        printf("number_of_philosophers, time_to_die, time_to_eat, time_to_sleep\n");
        return (1);
    }
    else if(ac == 2)
    {
        printf("You need to give 3 more parameters: ");
        printf("time_to_die, time_to_eat, time_to_sleep\n");
        return (1);
    }
    else if(ac == 3)
    {
        printf("You need to give 2 more parameters: ");
        printf("time_to_eat, time_to_sleep\n");
        return (1);
    }
    else if(ac == 4)
    {
        printf("You need to give 1 more parameter: ");
        printf("time_to_sleep\n");
        return (1);
    }
    else if(ac == 5)
    {
        return (0);
    }
    else
    {
        printf("You gave too many parameters\n");
        return (1);
    }
}
