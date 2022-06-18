/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:31:30 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/18 18:17:14 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	sem_unlink("death");
	sem_unlink("forks");
	sem_unlink("print");
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
	int i;

	i = 0;
	if ((get_current_time() - phil->last_time_eat) > phil->data->time_to_die)
	{
		sem_wait(phil->data->print_smphr);
		sem_wait(phil->data->death_smphr);
		printf("%ld %d died\n", get_current_time() - \
			phil->data->thread_start_time, phil->id + 1);
		while (i < phil->data->num_of_phils)
			kill(phil->data->phils[i++].pid, SIGKILL);
		phil->data->phil_is_dead = 1;
		sem_post(phil->data->death_smphr);
	}
}
