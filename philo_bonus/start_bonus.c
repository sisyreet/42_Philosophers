/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:52:22 by kos               #+#    #+#             */
/*   Updated: 2022/07/01 20:55:19 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*dm(void *phil)
{
	t_philo	*philo;

	philo = (t_philo *)phil;
	while (1)
	{
		death_check(philo->env, philo);
		usleep(1000);
		if (check_eat_semaphore(philo->env, philo))
			break ;
	}
	return (NULL);
}

void	routine(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	sem_wait(env->forks_sem);
	print_actions(env, philo->id, "has taken a fork");
	sem_wait(env->forks_sem);
	print_actions(env, philo->id, "has taken a fork");
	sem_wait(env->eat_sem);
	print_actions(env, philo->id, "is eating");
	philo->eats_done++;
	philo->last_time_eat = get_current_time();
	sem_post(env->eat_sem);
	smart_usleep(env->time_to_eat);
	sem_post(env->forks_sem);
	sem_post(env->forks_sem);
}

void	action(t_philo *philo)
{
	philo->last_time_eat = get_current_time();
	pthread_create(&philo->death_check_thread, NULL, dm, (void *)philo);
	if (philo->id % 2)
		usleep(10000);
	while (1)
	{
		routine(philo);
		if (check_death_semaphore(philo->env)
			|| (check_eat_semaphore(philo->env, philo)))
			break ;
		print_actions(philo->env, philo->id, "is sleeping");
		smart_usleep(philo->env->time_to_sleep);
		print_actions(philo->env, philo->id, "is thinking");
		if (check_death_semaphore(philo->env))
			break ;
	}
	pthread_join(philo->death_check_thread, NULL);
	if (check_death_semaphore(philo->env))
		exit (1);
	exit (0);
}

void	end_process(t_env *env)
{
	int	i;
	int	status;

	i = 0;
	while (i < env->phils_amount)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < env->phils_amount)
			{
				kill(env->philo[i].pid, SIGTERM);
				i++;
			}
			break ;
		}
		i++;
	}
	destroy_semaphores(env);
}

void	start_process(t_env *env)
{
	int	i;

	i = 0;
	env->thread_start = get_current_time();
	while (i < env->phils_amount)
	{
		env->philo[i].pid = fork();
		if (env->philo[i].pid < 0)
			exit_with_message("fork failed!", 12);
		if (env->philo[i].pid == 0)
			action(&env->philo[i]);
		i++;
	}
	end_process(env);
}
