/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 16:51:31 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/19 16:56:51 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

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