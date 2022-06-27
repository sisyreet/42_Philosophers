/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:14:14 by kos               #+#    #+#             */
/*   Updated: 2022/06/27 23:12:12 by kos              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_env env;

	check_args(argc, argv);
	init_env(&env, argv);
	start_process(&env);
	return (0);
}