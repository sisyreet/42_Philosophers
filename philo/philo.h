/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:32:48 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/30 21:14:37 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h> 
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

struct					s_data;
typedef struct s_data	t_data;
typedef pthread_mutex_t	t_mutex;
typedef struct timeval	t_timeval;

typedef struct s_fork
{
	t_mutex		mutex;
}	t_fork;

typedef struct s_phil
{
	t_fork		*forks;
	t_data		*data;

	pthread_t	th_id;
	int			id;
	long		last_time_eat;
	int			number_of_eats;
	int			notepme;
}	t_phil;

typedef struct s_data
{
	int			num_of_phils;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			notepme;
	int			phil_is_dead;
	int			num_p_ate_all;

	long		thread_start_time;
	t_mutex		print_mutex;
	t_mutex		death_mutex;
	t_phil		*phils;
	t_fork		*forks;
}	t_data;

int		ft_atoi(const char *nptr);
int		init_data(int argc, char **argv, t_data *data);
size_t	ft_strlen(const char *s);
void	*routine(void *phils);
int		check_args(int argc, char **argv);
void	print_fork(t_phil *phil, int fork);
void	print_eat(t_phil *phil);
void	print_rest(t_phil *phil);
void	put_back_fork(t_phil *phil);
long	get_current_time(void);
void	smart_usleep(int ttsz);
int		check_malloc(t_data *data);
void	ft_free(t_data *data);
int		join_threads(t_data *data);
void	exit_with_message(char *message);

#endif
