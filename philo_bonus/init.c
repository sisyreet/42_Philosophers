/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:56:15 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/18 18:15:24 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	wait_for_philosophers(t_data *data)
{
	while (1)
	{
		sem_wait(data->death_smphr);
		if (data->phil_is_dead)
			return (0);
		if (data->num_p_ate_all == data->num_of_phils)
			return (0);
		sem_post(data->death_smphr);
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
		data->phils[i].pid = fork();
		if (data->phils[i].pid < 0)
			return (-1);
		if (data->phils[i].pid == 0)
		{
			data->phils[i].id = i;
			routine(&data->phils[i]);
		}
		i++;
	}
	return (0);
}

int	init_semaphores(t_data *data)
{
	data->forks = sem_open("forks", O_CREAT, data->num_of_phils);
	if (!data->forks)
		return (1);
	data->death_smphr = sem_open("death", O_CREAT, 1);
	if (!data->death_smphr)
		return (1);
	data->print_smphr = sem_open("print", O_CREAT, 1);
	if (!data->print_smphr)
		return (1);
	return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->num_of_phils = ft_atoi(argv[1]);
	data->phils = malloc(sizeof(t_phil) * data->num_of_phils);
	if (check_malloc(data))
		return (1);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->notepme = ft_atoi(argv[5]);
	else
		data->notepme = -112;
	data->phil_is_dead = 0;
	data->num_p_ate_all = 0;
	if (init_semaphores(data) || init_philosophers(data))
		return (1);
	wait_for_philosophers(data);
	return (0);
}
