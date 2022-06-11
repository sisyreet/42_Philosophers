/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:43:51 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/11 14:48:54 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int checks(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return(-1);
	return 0;
}

int	main(int argc, char **argv)
{
	t_data *data;
	if (checks(argc, argv))
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (init_data(argc, argv, data))
		return (0);
	// free
	return (0);
}