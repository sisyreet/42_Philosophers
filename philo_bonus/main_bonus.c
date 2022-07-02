/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:14:14 by kos               #+#    #+#             */
/*   Updated: 2022/07/02 16:07:35 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	long long int	k;
	int				minus;

	i = 0;
	k = 0;
	minus = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = 1 * (-1);
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		k = k * 10 + (nptr[i++] - '0');
		if (k > 2147483647)
			return (0);
		if (k < 0)
			return (0);
	}
	return (k * minus);
}

int	main(int argc, char **argv)
{
	t_env	env;

	check_args(argc, argv);
	init_env(&env, argv);
	start_process(&env);
	return (0);
}
