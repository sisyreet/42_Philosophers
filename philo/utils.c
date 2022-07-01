/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:31:30 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/30 21:13:24 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_with_message(char *message)
{
	printf("%s\n", message);
	exit (1);
}

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

int	ft_atoi(const char *nptr)
{
	int				i;
	long long int	k;
	int				minus;

	i = 0;
	k = 0;
	minus = 1;
	while ((nptr[i] > 8 && nptr[i] < 14) || (nptr[i] == 32))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus = 1 * (-1);
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		k = k * 10 + (nptr[i++] - '0');
		if (k < 0)
			return (0);
	}
	return (k * minus);
}
