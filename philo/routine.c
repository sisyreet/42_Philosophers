/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:24:15 by sisyreet          #+#    #+#             */
/*   Updated: 2022/04/08 12:16:27 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	print_fork(t_phil *phil, int fork)
{
	if (fork == 1)
	{
		pthread_mutex_lock(&phil->data->print_mutex);
		printf("%ld %d has taken a left fork\n", get_current_time() - \
			phil->data->thread_start_time, phil->id + 1);
		pthread_mutex_unlock(&phil->data->print_mutex);
	}
	if (fork == 2)
	{
		pthread_mutex_lock(&phil->data->print_mutex);
		printf("%ld %d has taken a right fork\n", get_current_time() - \
			phil->data->thread_start_time, phil->id + 1);
		pthread_mutex_unlock(&phil->data->print_mutex);
	}
}

void	take_fork(t_phil *phil)
{
	if (phil->id == 0)
	{
		death_check(phil);
		pthread_mutex_lock(&phil->forks[phil->data->num_of_phils - 1].mutex);
		print_fork(phil, 1);
		if (phil->data->num_of_phils == 1)
		{
			smart_usleep(phil->data->time_to_die + 1);
			death_check(phil);
		}
		death_check(phil);
		pthread_mutex_lock(&phil->forks[phil->id].mutex);
		print_fork(phil, 2);
	}
	else
	{
		death_check(phil);
		pthread_mutex_lock(&phil->forks[phil->id].mutex);
		print_fork(phil, 2);
		death_check(phil);
		pthread_mutex_lock(&phil->forks[phil->id - 1].mutex);
		print_fork(phil, 1);
	}
	death_check(phil);
	print_eat(phil);
}

void	print_eat(t_phil *phil)
{
	pthread_mutex_lock(&phil->data->print_mutex);
	printf("%ld %d is eating\n", get_current_time() - \
		phil->data->thread_start_time, phil->id + 1);
	phil->last_time_eat = get_current_time();
	pthread_mutex_unlock(&phil->data->print_mutex);
	smart_usleep(phil->data->time_to_eat);
	if (phil->id == 0)
	{
		pthread_mutex_unlock(&phil->forks[phil->data->num_of_phils - 1].mutex);
		pthread_mutex_unlock(&phil->forks[phil->id].mutex);
	}
	else
	{
		pthread_mutex_unlock(&phil->forks[phil->id].mutex);
		pthread_mutex_unlock(&phil->forks[phil->id - 1].mutex);
	}
	phil->number_of_eats++;
	print_rest(phil);
}

void	print_rest(t_phil *phil)
{
	pthread_mutex_lock(&phil->data->print_mutex);
	printf("%ld %d is sleeping\n", get_current_time() - \
		phil->data->thread_start_time, phil->id + 1);
	pthread_mutex_unlock(&phil->data->print_mutex);
	smart_usleep(phil->data->time_to_sleep);
	pthread_mutex_lock(&phil->data->print_mutex);
	printf("%ld %d is thinking\n", get_current_time() - \
		phil->data->thread_start_time, phil->id + 1);
	pthread_mutex_unlock(&phil->data->print_mutex);
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
		pthread_mutex_lock(&phil->data->death_mutex);
		if (phil->data->phil_is_dead)
			break ;
		pthread_mutex_unlock(&phil->data->death_mutex);
		if (phil->number_of_eats == phil->data->notepme)
			break ;
	}
	if (phil->notepme == phil->number_of_eats)
	{
		pthread_mutex_lock(&phil->data->death_mutex);
		phil->data->num_p_ate_all++;
		pthread_mutex_unlock(&phil->data->death_mutex);
	}
	return (NULL);
}
