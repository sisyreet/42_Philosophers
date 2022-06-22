/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:11:35 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/22 20:16:28 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	exit_with_message(char *message)
{
	printf("%s\n", message);
	exit (-1);
}

long	get_current_time(void)
{
	t_timeval	tm;

	gettimeofday(&tm, 0);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

void	smart_usleep(int tts)
{
	long long	temp;

	temp = get_current_time() + tts;
	while (get_current_time() < temp)
		usleep(1);
}

void	print_actions(t_env *env, int id, char *text)
{
	sem_wait(env->print);
	if (!env->philo_is_dead)
	{
		printf("%ld", get_current_time() - env->start_time);
		printf(" %d ", id +  1);
		printf("%s \n", text);
	}
	sem_post(env->print);
}

void	destroy_semaphores(t_env *env)
{
	sem_close(env->forks);
	sem_close(env->print);
	sem_close(env->eat);
	sem_close(env->death);
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/eat");
	sem_unlink("/death");
}
