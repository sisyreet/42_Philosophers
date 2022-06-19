/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:54:54 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/19 16:59:06 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(env));
	if (!env)
		exit_with_message("something went wrong in very begining...");
	checks(argc, argv);
	init_env(argv, env);
	start_processes(env);
}
