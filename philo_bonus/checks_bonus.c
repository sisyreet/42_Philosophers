/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:55:48 by kos               #+#    #+#             */
/*   Updated: 2022/07/01 19:02:38 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_for_letters(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv [i][j] > '9')
				exit_with_message("Incorrect arguments!", 6);
			j++;
		}
		i++;
	}
}

void	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		exit_with_message("Usage: ./philo_bonus 5 800 200 200 7", 3);
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		exit_with_message("Incorrect arguments!", 4);
	if (argv[5] && ft_atoi(argv[5]) <= 0)
		exit (0);
	check_for_letters(argv);
	if (ft_atoi(argv[1]) > 200)
		exit_with_message("Too many philosophers!", 6);
}
