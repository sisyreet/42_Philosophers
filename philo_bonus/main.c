/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:23:39 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/18 17:15:58 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	if (check_args(argc, argv))
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	if (init_data(argc, argv, data))
		return (1);
	ft_free(data);
	return (0);
}
