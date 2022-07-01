/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:15:43 by kos               #+#    #+#             */
/*   Updated: 2022/07/01 20:51:36 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_semaphores(t_env *env)
{
	sem_unlink("death_sem");
	sem_unlink("print_sem");
	sem_unlink("eat_sem");
	sem_unlink("forks_sem");
	env->death_sem = sem_open("death_sem", O_CREAT, 0777, 1);
	env->print_sem = sem_open("print_sem", O_CREAT, 0777, 1);
	env->eat_sem = sem_open("eat_sem", O_CREAT, 0777, 1);
	env->forks_sem = sem_open("forks_sem", O_CREAT, 0777, env->phils_amount);
	if (env->death_sem == SEM_FAILED || env->print_sem == SEM_FAILED
		|| env->eat_sem == SEM_FAILED || env->forks_sem == SEM_FAILED)
		exit_with_message("semaphores initialization failed!", 2);
}

void	init_philosophers(t_env *env)
{
	int	i;

	env->philo = malloc(sizeof(t_philo) * env->phils_amount);
	if (!env->philo)
		exit_with_message("philo array allocation failed", 1);
	i = 0;
	while (i < env->phils_amount)
	{
		env->philo[i].id = i + 1;
		env->philo[i].is_dead = 0;
		env->philo[i].last_time_eat = 0;
		env->philo[i].env = env;
		env->philo[i].eats_done = 0;
		i++;
	}
	init_semaphores(env);
}

void	init_env(t_env *env, char **argv)
{
	env->phils_amount = ft_atoi(argv[1]);
	env->time_to_die = ft_atoi(argv[2]);
	env->time_to_eat = ft_atoi(argv[3]);
	env->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		env->notepme = ft_atoi(argv[5]);
	else
		env->notepme = -1;
	env->is_dead = 0;
	init_philosophers(env);
}
