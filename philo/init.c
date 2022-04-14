/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:56:15 by sisyreet          #+#    #+#             */
/*   Updated: 2022/04/08 12:07:11 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	wait_for_philosophers(t_data *data)
{
	while (1)
	{
		printf("");
		pthread_mutex_lock(&data->death_mutex);
		if (data->phil_is_dead)
			return (0);
		if (data->num_p_ate_all == data->num_of_phils)
			return (0);
		pthread_mutex_unlock(&data->death_mutex);
	}
	ft_free(data);
	return (0);
}

int	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	data->thread_start_time = get_current_time();
	while (i < data->num_of_phils)
	{
		data->phils[i].id = i;
		data->phils[i].forks = data->forks;
		data->phils[i].data = data;
		data->phils[i].number_of_eats = 0;
		data->phils[i].last_time_eat = get_current_time();
		data->phils[i].notepme = data->notepme;
		if (pthread_create(&data->phils[i].th_id, NULL,
				&routine, &data->phils[i]))
			return (1);
		pthread_detach(data->phils[i].th_id);
		i++;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_phils)
	{
		if (pthread_mutex_init(&(data->forks[i].mutex), 0))
		{
			printf("mutex init failed\n");
			return (1);
		}
		data->phils->forks = data->forks;
		i++;
	}
	if (pthread_mutex_init(&data->death_mutex, 0))
	{
		printf("mutex init failed\n");
		return (1);
	}
	return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->num_of_phils = ft_atoi(argv[1]);
	data->phils = malloc(sizeof(t_phil) * data->num_of_phils);
	data->forks = malloc(sizeof(t_fork) * data->num_of_phils);
	if (check_malloc(data))
		return (1);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->notepme = ft_atoi(argv[5]);
	else
		data->notepme = -112;
	if (pthread_mutex_init(&data->print_mutex, 0))
	{
		printf("mutex init failed\n");
		return (1);
	}
	data->phil_is_dead = 0;
	data->num_p_ate_all = 0;
	if (init_forks(data) || init_philosophers(data))
		return (1);
	wait_for_philosophers(data);
	return (0);
}
