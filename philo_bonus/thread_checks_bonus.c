/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_checks_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:51:31 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/22 20:11:06 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	death_semaphore_check(t_env *env)
{
	sem_wait(env->death);
	if (env->philo_is_dead)
	{
		sem_post(env->death);
		return (1);
	}
	sem_post(env->death);
	return (0);
}

int	eat_check(t_env *env, t_philo *philo)
{
	sem_wait(env->eat);
	if (env->notepme != -1 && philo->eats_done >= env->notepme)
	{
		sem_post(env->eat);
		return (1);
	}
	sem_post(env->eat);
	return (0);
}

void	death_check(t_env *env, t_philo *philo)
{
	sem_wait(env->eat);
	if (get_current_time() - philo->last_eat_time > env->time_to_eat)
	{
		print_actions(env, philo->id, "died");
		sem_wait(env->death);
		env->philo_is_dead = 1;
		sem_post(env->death);
		sem_wait(env->print);
		sem_post(env->eat);
		exit (1);
	}
	sem_post(env->eat);
}
