/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:43:47 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/11 15:59:29 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
	int	num_of_phils;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	notepme;
	
}	t_data;

typedef struct s_philo
{
	int		id;
	long	last_time_eat;
	int		number_of_eats;
	int		notepme;
	int		pid;
}	t_philo;

int	ft_atoi(const char *nptr);

#endif