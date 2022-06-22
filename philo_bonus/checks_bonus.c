/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:05:35 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/20 19:07:16 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	check_for_letters(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	checks(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
		exit_with_message("Usage: ./philo_bonus 5 800 200 200 7");
	if (check_for_letters(argv))
		exit_with_message("Arguments must be numeric and more than 0!");
	if (ft_atoi(argv[1]) > 200)
		exit_with_message("Too much processes, try number less then 200");
}