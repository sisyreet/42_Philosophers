/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:28:53 by sisyreet          #+#    #+#             */
/*   Updated: 2022/07/01 19:04:49 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_malloc(t_data *data)
{
	if (!data->phils || !data->forks)
	{
		printf("malloc returned NULL\n");
		return (1);
	}
	return (0);
}

int	check_for_letters(char **argv)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		exit_with_message("Usage: ./philo_bonus 5 800 200 200 7");
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0
		|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		exit_with_message("Incorrect arguments!");
	if (argv[5] && ft_atoi(argv[5]) <= 0)
		exit (0);
	if (check_for_letters(argv))
		exit_with_message("Incorrect arguments!");
	if (ft_atoi(argv[1]) > 200)
		exit_with_message("Too many philosophers!");
	return (0);
}
