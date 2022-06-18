/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:28:53 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/18 16:55:43 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	check_malloc(t_data *data)
{
	if (!data->phils)
	{
		printf("malloc returned NULL\n");
		return (1);
	}
	return (0);
}

// int	check_numbers(char **argv)
// {
// 	int	i;
// 	int	j;

// 	i = 1;
// 	while (argv[i])
// 	{
// 		j = 0;
// 		while (argv[i][j])
// 		{
// 			if (argv[i][j] > '9' || argv[i][j] < '0')
// 			{
// 				printf("arguments must be only numbers 0-9!\n");
// 				return (1);
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	check_numbers(char **argv)
{
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 1
		|| ft_atoi(argv[4]) < 1)
	{
		printf("Invalid aguments! Arguments must be numeric and positive\n");
		return (1);
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("usage: ./philosophers 5 800 200 200 7(optional argument)\n");
		return (1);
	}
	if (check_numbers(argv))
		return (1);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
	{
		printf("number of philosophers must from 1 to 200!\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 1 || ft_atoi(argv[3]) < 60
		|| ft_atoi(argv[4]) < 60)
	{
		printf("invalid parameters! ttd must be > 0, tte and tts >= 60\n");
		return (1);
	}
	return (0);
}
