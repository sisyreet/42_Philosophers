/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 12:59:37 by sisyreet          #+#    #+#             */
/*   Updated: 2022/06/22 20:09:11 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/time.h>
# include <pthread.h>

struct s_philo;

typedef struct s_env
{
	int				philos_amount;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_think;
	int				notepme;
	long			start_time;
	int				philo_is_dead;
	sem_t			*print;
	sem_t			*death;
	sem_t			*eat;
	sem_t			*forks;
	struct s_philo	*philos;
}	t_env;

typedef struct s_philo
{
	pid_t		pid;
	int			id;
	int			eats_done;
	int			last_eat_time;
	
	pthread_t	death_check_thread;
	t_env		*env;
}	t_philo;

typedef struct timeval	t_timeval;

int		ft_atoi(char *str);
void	exit_with_message(char *message);
void	checks(int argc, char **argv);
void	init_env(char **argv, t_env *env);
void	init_philos(t_env *env);
long	get_current_time(void);
int		eat_check(t_env *env, t_philo *philo);
void	smart_usleep(int tts);
void	print_actions(t_env *env, int id, char *text);
int		death_semaphore_check(t_env *env);
void	start_processes(t_env *env);
void	death_check(t_env *env, t_philo *philo);
void	destroy_semaphores(t_env *env);

#endif