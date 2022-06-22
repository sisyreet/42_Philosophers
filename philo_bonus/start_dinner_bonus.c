/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:40:24 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/22 19:35:23 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	routine(t_philo *philo)
{
	sem_wait(philo->env->forks);
	print_actions(philo->env, philo->id, "taken a fork");
	sem_wait(philo->env->forks);
	print_actions(philo->env, philo->id, "taken a fork");
	sem_wait(philo->env->eat);
	philo->eats_done++;
	philo->last_eat_time = get_current_time();
	sem_post(philo->env->eat);
	print_actions(philo->env, philo->id, "is eating");
	smart_usleep(philo->env->time_to_eat);
	sem_post(philo->env->forks);
	sem_post(philo->env->forks);
}

void	*check_status(void *phil) // *?
{
	t_philo *philo;

	philo = (t_philo *)phil;
	while (1)
	{
		death_check(philo->env, philo);
		usleep (1000);
		if (eat_check(philo->env, philo))
			break;
	}
	return (NULL);
}

void	start_death_threads(t_philo *philo)
{
	philo->last_eat_time = get_current_time();
	pthread_create(&(philo->death_check_thread), NULL, check_status, (void *)philo);
	if (philo->id % 2)
		usleep (10000);
	while (1)
	{
		routine(philo);
		if (death_semaphore_check(philo->env) || eat_check(philo->env, philo))
			break ;
		print_actions(philo->env, philo->id, "is sleeping");
		smart_usleep(philo->env->time_to_sleep);
		print_actions(philo->env, philo->id, "is thinking");
		if (death_semaphore_check(philo->env))
			break ;
	}
	pthread_join(philo->death_check_thread, NULL);
	if (death_semaphore_check(philo->env))
		exit (1);
	exit (0);
}

void	stop_processes(t_env *env)
{
	int	responce;
	int	i;
	
	i = 0;
	while (i < env->philos_amount) 
	{
		waitpid(-1, &responce, 0);
		if (responce != 0)
		{
			i = 0;
			while (i < env->philos_amount)
			{
				kill(env->philos[i].pid, SIGTERM);
				i++;
			}
			break ;
		}
		i++;
	}
	destroy_semaphores(env);
}

void	start_processes(t_env *env)
{
	int	i;

	i = 0;
	env->start_time = get_current_time();
	while (i < env->philos_amount)
	{
		env->philos[i].pid = fork();
		if (env->philos[i].pid < 0)
			exit_with_message("something went wrong...") ;
		if (!env->philos[i].pid)
			start_death_threads(&env->philos[i]);
		usleep (100);
		i++;
	}
	stop_processes(env);
}