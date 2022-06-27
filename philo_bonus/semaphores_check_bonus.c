/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semaphores_check_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 21:47:11 by kos               #+#    #+#             */
/*   Updated: 2022/06/27 22:26:42 by kos              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	check_death_semaphore(t_env *env)
{
	sem_wait(env->death_sem);
	if (env->is_dead)
	{
		sem_post(env->death_sem);
		return (1);
	}
	sem_post(env->death_sem);
	return (0);
}

int	check_eat_semaphore(t_env *env, t_philo *philo)
{
	sem_wait(env->eat_sem);
	if (env->notepme != -1 && philo->eats_done >= env->notepme)
	{
		sem_post(env->eat_sem);
		return (1);
	}
	sem_post(env->eat_sem);
	return (0);
}

void	death_check(t_env *env, t_philo *philo)
{
	sem_wait(env->eat_sem);
	if (get_current_time() - philo->last_time_eat > env->time_to_die)
	{
		print_actions(env, philo->id, "died");
		sem_wait(env->death_sem);
		env->is_dead = 1;
		sem_post(env->death_sem);
		sem_wait(env->print_sem);
		sem_post(env->eat_sem);
		exit (1);
	}
	sem_post(env->eat_sem);
}
