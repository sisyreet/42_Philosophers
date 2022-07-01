/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sisyreet <sisyreet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:05:06 by sisyreet          #+#    #+#             */
/*   Updated: 2022/07/01 20:51:03 by sisyreet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h> 
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_env	t_env;
typedef struct timeval	t_timeval;

typedef struct s_philo
{
	int			id;
	long long	last_time_eat;
	int			eats_done;
	int			is_dead;
	pid_t		pid;
	t_env		*env;
	pthread_t	death_check_thread;
}	t_philo;

typedef struct s_env
{
	int		phils_amount;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		notepme;
	int		is_dead;
	long	thread_start;
	sem_t	*death_sem;
	sem_t	*eat_sem;
	sem_t	*forks_sem;
	sem_t	*print_sem;
	t_philo	*philo;

}	t_env;

int		ft_atoi(const char *nptr);
void	exit_with_message(char *msg, int code);
void	smart_usleep(int tts);
long	get_current_time(void);
void	init_env(t_env *env, char **argv);
void	start_process(t_env *env);
int		check_eat_semaphore(t_env *env, t_philo *philo);
void	death_check(t_env *env, t_philo *philo);
int		check_death_semaphore(t_env *env);
void	print_actions(t_env *env, int id, char *action);
void	destroy_semaphores(t_env *env);
void	check_args(int argc, char **argv);

#endif