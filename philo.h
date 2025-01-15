/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tndreka <tndreka@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 00:58:55 by tndreka           #+#    #+#             */
/*   Updated: 2025/01/15 19:01:57 by tndreka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

// Struct for the philosophers


typedef struct s_dinin
{
    int                 index;
    int                 time_to_die;
    int                 time_to_eat;
    int                 time_to_sleep;
} t_dining;

//Argument check functions
int arg_checker(int ac, char **av);
int analyze_args(int ac, char **av);
//Utils functions
int fT_isdigit(char n);
int	ft_atoi(const char *str);

#endif