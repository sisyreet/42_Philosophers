/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:55:31 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/19 16:37:17 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	init_semaphores(t_env *env)
{
	sem_unlink("forks");
	sem_unlink("death");
	sem_unlink("eat");
	sem_unlink("print");
	env->forks = sem_open("forks", O_CREAT, env->philos_amount);
	env->death = sem_open("death", O_CREAT, 1);
	env->eat = sem_open("eat", O_CREAT, 1);
	env->print = sem_open("print", O_CREAT, 1);
	if (!env->print || !env->death || !env->forks || !env->eat)
		exit_with_message("semaphore initialization failed...");
}

void	init_philos(t_env *env)
{
	int	i;
	t_philo	*philos;

	philos = (t_philo *)malloc(sizeof(t_philo) * env->philos_amount);
	if (!philos)
		exit_with_message("philos malloc failed...");
	i = 0;
	while (i < env->philos_amount)
	{
		philos[i].env = env;
		philos[i].id = i + 1;
		philos[i].eats_done = 0;
		philos[i].last_eat_time = 0;
		i++;
	}
	env->philos = philos;
	init_semaphores(env);
}

void	init_env(char **argv, t_env *env)
{
	env->philos_amount = ft_atoi(argv[1]);
	env->time_to_eat = ft_atoi(argv[2]);
	env->time_to_sleep = ft_atoi(argv[3]);
	env->time_to_think = ft_atoi(argv[4]);
	if (argv[5])
		env->notepme = ft_atoi(argv[5]);
	else
		env->notepme = -1;
	init_philos(env);
}
