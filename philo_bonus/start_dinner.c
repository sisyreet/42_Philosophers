/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:40:24 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/19 17:00:45 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	*check_status(void *phil)
{
	t_philo *philo;

	philo = (t_philo *)phil;
	while (1)
	{
		check_death(philo->env, philo);
		usleep (1000);
		if (eat_check(philo->env, philo))
			break;
	}
	return (NULL);
}

void	routine(t_philo *philo)
{
	philo->last_eat_time = get_current_time();
	pthread_create(philo->death_check_thread, NULL, check_status, (void *)philo);
	if (philo->id % 2)
		usleep (10000);
	while (1)
	{
		dining(philo);
		if (death_check(env) || eat_check(env, philo)) //ended here
	}
}

void	end_dinner(t_env *env)
{
	int	i;
	int	responce;
	
	i = 0;
	while (i < env->philos_amount) 
	{
		waitpid(-1, &responce, 0);
		if (responce != 0)
		{
			i = 0;
			while (i < env->philos_amount)
			{
				kill(env->philos[i].pid, SIGKILL);
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
		if (!env->philos[i].pid)
			routine(&env->philos[i]);
		if (env->philos[i].pid)
			return ;
		usleep (100);
		i++;
	}
	monitor(env);
}