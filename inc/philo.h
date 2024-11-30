/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:05:37 by otodd             #+#    #+#             */
/*   Updated: 2024/11/30 11:35:42 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stddef.h>
# include <pthread.h>
# define __USE_XOPEN 1
# include <sys/time.h>
# include <unistd.h>
# include <stdatomic.h>
# include <stdbool.h>
# include <stdint.h>

# define CHOP "has taken a chopstick"
# define THINK "is thinking about food."
# define NAP "is sleeping..."
# define EAT "is eating a donut."
# define DEAD "has died."

/*    COLOURS     */

# define BRED "\e[1;31m"
# define BBLU "\e[1;34m"
# define RESET "\e[0m"

/*     STRUCTS     */

struct	s_data;

typedef struct s_philo
{
	int				id;
	atomic_int		eat_cnt;
	atomic_long		last_meal;
	pthread_t		thread;
	struct s_data	*data;
	pthread_mutex_t	*l_chopstick;
	pthread_mutex_t	*r_chopstick;
	atomic_bool		full;
}	t_philo;

typedef struct s_data
{
	atomic_bool		stop;
	t_philo			*pandas;
	int				nop;
	int				life_t;
	int				eat_t;
	int				nap_t;
	int				must_eat_t;
	long			start_t;
	pthread_mutex_t	*chopsticks;
	pthread_mutex_t	print_lock;
}	t_data;

/*     ROUTINE     */

void			*ft_routine(void *p);
void			ft_taken_chopstick(t_philo *philo);
void			ft_eat(t_philo *philo);
void			ft_nap(t_philo *philo);
void			ft_think(t_philo *philo);
void			ft_dead(t_philo *philo);
void			ft_zookeeper(t_data *data);

/*     INIT     */

bool			ft_parse_args(t_data *data, int ac, char **av);
void			ft_init_data(t_data *data);
void			ft_init_philos(t_data *data);
void			ft_init_mutexes(t_data *data);
void			ft_exit(t_data *data);
void			ft_init_threads(t_data *data);

/*     UTILS     */
void	ft_write(t_philo *philo, const char *msg);
bool			ft_full(t_data *data);
long			ft_time(void);
void			ft_usleep(long time);
int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				ft_ischeck_str(char *str, int (*f)(int));

#endif