/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 14:41:39 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/11 16:26:06 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"

int	some_philo_action(t_data *data, t_philo *philo, int id)
{
	sleep(1);
	printf("My pid is %d\n", philo->pid);
	return (0);
}

int start_philos(t_data *data)
{
	int	i;
	int	id;
	t_philo *philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (-1);
	i = 0;
	while (i < data->num_of_phils)
	{
		id = fork();
		if (id < 0)
			return (-1);
		if(id == 0)
		{
			philo->pid = getpid();
			philo->id = i;
			some_philo_action(data, philo, id);
		}
		else
			return (0);
		i++;
		usleep(100);
	}
	printf("POST SDAL %d <0.", getpid());
	return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->num_of_phils = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		data->notepme = ft_atoi(argv[5]);
	start_philos(data);
	return (0);
}