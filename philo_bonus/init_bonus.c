/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:55:31 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/22 20:10:52 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	init_semaphores(t_env *env)
{
	sem_unlink("forks");
	sem_unlink("death");
	sem_unlink("eat");
	sem_unlink("print");
	env->forks = sem_open("forks", O_CREAT, S_IRWXU, env->philos_amount);
	env->death = sem_open("death", O_CREAT, S_IRWXU, 1);
	env->eat = sem_open("eat", O_CREAT, S_IRWXU, 1);
	env->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	if (env->print <= 0 || env->death <= 0 || env->forks <= 0 || env->eat <= 0)
		exit_with_message("semaphore initialization failed...");
}

void	init_philos(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->philos_amount)
	{
		env->philos[i].env = env;
		env->philos[i].id = i;
		env->philos[i].eats_done = 0;
		env->philos[i].last_eat_time = 0;
		i++;
	}
	init_semaphores(env);
}

void	init_env(char **argv, t_env *env)
{
	env->philos = malloc(sizeof(t_philo) * env->philos_amount);
	if (!env->philos)
		exit_with_message("philos malloc failed...");
	env->philos_amount = ft_atoi(argv[1]);
	env->time_to_eat = ft_atoi(argv[2]);
	env->time_to_sleep = ft_atoi(argv[3]);
	env->time_to_think = ft_atoi(argv[4]);
	if (argv[5])
		env->notepme = ft_atoi(argv[5]);
	else
		env->notepme = -1;
	env->philo_is_dead = 0;
	init_philos(env);
}
