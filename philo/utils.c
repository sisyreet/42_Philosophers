/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kos <kos@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:31:30 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/28 22:23:25 by kos              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		pthread_mutex_destroy(&data->forks[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->death_mutex);
	free(data->forks);
	free(data->phils);
	free(data);
}

void	smart_usleep(int tts)
{
	long long	temp;

	temp = get_current_time() + tts;
	while (get_current_time() < temp)
		usleep(1);
}

long	get_current_time(void)
{
	t_timeval	tm;

	gettimeofday(&tm, 0);
	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
}

void	death_check(t_phil *phil)
{
	if ((get_current_time() - phil->last_time_eat) > phil->data->time_to_die)
	{
		pthread_mutex_lock(&phil->data->print_mutex);
		pthread_mutex_lock(&phil->data->death_mutex);
		printf("%ld %d died\n", get_current_time() - \
			phil->data->thread_start_time, phil->id + 1);
		phil->data->phil_is_dead = 1;
		pthread_mutex_unlock(&phil->data->death_mutex);
	}
}
