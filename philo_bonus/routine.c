/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:24:15 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/18 17:35:27 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_fork(t_phil *phil, int fork)
{
	if (fork == 1)
	{
		sem_wait(phil->data->print_smphr);
		printf("%ld %d has taken a left fork\n", get_current_time() - \
			phil->data->thread_start_time, phil->id + 1);
		sem_post(phil->data->print_smphr);
	}
	if (fork == 2)
	{
		sem_wait(phil->data->print_smphr);
		printf("%ld %d has taken a right fork\n", get_current_time() - \
			phil->data->thread_start_time, phil->id + 1);
		sem_post(phil->data->print_smphr);
	}
}

void	take_fork(t_phil *phil)
{
	if (phil->id == 0)
	{
		death_check(phil);
		sem_wait(phil->forks);
		print_fork(phil, 1);
		if (phil->data->num_of_phils == 1)
		{
			smart_usleep(phil->data->time_to_die + 1);
			death_check(phil);
		}
		death_check(phil);
		sem_post(phil->forks);
		print_fork(phil, 2);
	}
	else
	{
		death_check(phil);
		sem_wait(phil->forks);
		print_fork(phil, 2);
		death_check(phil);
		sem_wait(phil->forks);
		print_fork(phil, 1);
	}
	death_check(phil);
	print_eat(phil);
}

void	print_eat(t_phil *phil)
{
	sem_wait(phil->data->print_smphr);
	printf("%ld %d is eating\n", get_current_time() - \
		phil->data->thread_start_time, phil->id + 1);
	phil->last_time_eat = get_current_time();
	sem_post(phil->data->print_smphr);
	smart_usleep(phil->data->time_to_eat);
	if (phil->id == 0)
	{
		sem_post(phil->forks);
		sem_post(phil->forks);
	}
	else
	{
		sem_post(phil->forks);
		sem_post(phil->forks);
	}
	phil->number_of_eats++;
	print_rest(phil);
}

void	print_rest(t_phil *phil)
{
	sem_wait(phil->data->print_smphr);
	printf("%ld %d is sleeping\n", get_current_time() - \
		phil->data->thread_start_time, phil->id + 1);
	sem_post(phil->data->print_smphr);
	smart_usleep(phil->data->time_to_sleep);
	sem_wait(phil->data->print_smphr);
	printf("%ld %d is thinking\n", get_current_time() - \
		phil->data->thread_start_time, phil->id + 1);
	sem_post(phil->data->print_smphr);
}

void	*routine(void *data)
{
	t_phil	*phil;

	phil = (t_phil *)data;
	if (phil->id % 2 == 0 && phil->data->num_of_phils > 1)
		smart_usleep(200);
	while (1)
	{
		take_fork(phil);
		sem_wait(phil->data->death_smphr);
		if (phil->data->phil_is_dead)
			break ;
		sem_post(phil->data->death_smphr);
		if (phil->number_of_eats == phil->data->notepme)
			break ;
	}
	if (phil->notepme == phil->number_of_eats)
	{
		sem_wait(phil->data->death_smphr);
		phil->data->num_p_ate_all++;
		sem_post(phil->data->death_smphr);
	}
	return (NULL);
}
