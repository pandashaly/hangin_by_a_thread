/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:39:37 by ssottori          #+#    #+#             */
/*   Updated: 2024/11/30 17:02:35 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	ft_init_philos(t_data *data)
{
	ft_init_mutexes(data);
	ft_init_data(data);
	ft_init_threads(data);
}

void	ft_init_data(t_data *data)
{
	int		i;

	data->pandas = malloc(sizeof(t_philo) * data->nop);
	i = -1;
	while (++i < data->nop)
	{
		data->pandas[i].id = i;
		data->pandas[i].eat_cnt = 0;
		data->pandas[i].last_meal = 0;
		data->pandas[i].data = data;
		data->pandas[i].full = false;
		data->pandas[i].l_chopstick = &data->chopsticks[i];
		data->pandas[i].r_chopstick = &data->chopsticks[(i + 1) % data->nop];
	}
}

void	ft_init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	pthread_mutex_init(&data->print_lock, NULL);
	data->chopsticks = malloc(sizeof(pthread_mutex_t) * data->nop);
	while (++i < data->nop)
		pthread_mutex_init(&data->chopsticks[i], NULL);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nop)
		pthread_join(data->pandas[i].thread, NULL);
	pthread_mutex_destroy(&data->print_lock);
	i = -1;
	while (++i < data->nop)
		pthread_mutex_destroy(&data->chopsticks[i]);
	free(data->pandas);
	free(data->chopsticks);
}

void	ft_init_threads(t_data *data)
{
	int	i;

	data->start_t = ft_time();
	i = -1;
	while (++i < data->nop)
	{
		pthread_create(&data->pandas[i].thread,
			NULL, ft_routine, &data->pandas[i]);
	}
}
