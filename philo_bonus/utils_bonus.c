/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:16:56 by kos               #+#    #+#             */
/*   Updated: 2022/06/27 22:26:35 by kos              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

void	exit_with_message(char *msg, int code)
{
	printf("%s\n", msg);
	exit (code);
}

void	smart_usleep(int tts)
{
	long long	temp;

	temp = get_current_time() + tts;
	while (get_current_time() < temp)
		usleep(10);
}

long	get_current_time(void)
{
	t_timeval	tm;

	gettimeofday(&tm, 0);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

void	print_actions(t_env *env, int id, char *action)
{
	sem_wait(env->print_sem);
	if (!env->is_dead)
	{
		printf("%ld", get_current_time() - env->thread_start);
		printf(" %d ", id);
		printf("%s\n", action);
	}
	sem_post(env->print_sem);
}

void	destroy_semaphores(t_env *env)
{
	sem_close(env->forks_sem);
	sem_close(env->print_sem);
	sem_close(env->eat_sem);
	sem_close(env->death_sem);
	sem_unlink("/forks_sem");
	sem_unlink("/print_sem");
	sem_unlink("/eat_sem");
	sem_unlink("/death_sem");
}