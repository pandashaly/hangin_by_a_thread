/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:40:23 by ssottori          #+#    #+#             */
/*   Updated: 2024/11/30 16:40:25 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	ft_zookeeper(t_data *data)
{
	int		i;

	i = 0;
	while (!data->stop)
	{
		if (data->pandas[i].data->must_eat_t != -1)
			if (data->pandas[i].eat_cnt == data->pandas[i].data->must_eat_t)
				data->pandas[i].full = true;
		if (ft_full(data))
			data->stop = true;
		if (!data->pandas[i].full)
		{
			if (((ft_time() - data->start_t)
					- data->pandas[i].last_meal) > data->life_t)
			{
				if (!data->pandas[i].full)
				{
					ft_dead(&data->pandas[i]);
					data->stop = true;
				}
			}
		}
		i = (i + 1) % data->nop;
		ft_usleep(1);
	}
}

static bool	ft_take_chopsticks(t_philo *panda)
{
	if (panda->data->stop)
		return (false);
	if (panda->l_chopstick < panda->r_chopstick)
	{
		pthread_mutex_lock(panda->l_chopstick);
		ft_taken_chopstick(panda);
		if (panda->l_chopstick == panda->r_chopstick)
			return (false);
		pthread_mutex_lock(panda->r_chopstick);
		ft_taken_chopstick(panda);
	}
	else
	{
		pthread_mutex_lock(panda->r_chopstick);
		ft_taken_chopstick(panda);
		if (panda->l_chopstick == panda->r_chopstick)
			return (false);
		pthread_mutex_lock(panda->l_chopstick);
		ft_taken_chopstick(panda);
	}
	return (true);
}

bool	ft_eating(t_philo *panda)
{
	if (!ft_take_chopsticks(panda))
		return (false);
	ft_eat(panda);
	panda->last_meal = ft_time() - panda->data->start_t;
	panda->eat_cnt++;
	ft_usleep(panda->data->eat_t);
	pthread_mutex_unlock(panda->l_chopstick);
	pthread_mutex_unlock(panda->r_chopstick);
	return (true);
}

void	ft_dead(t_philo *panda)
{
	if (!panda->data->stop)
	{
		pthread_mutex_lock(&panda->data->print_lock);
		if (!panda->data->stop)
		{
			printf(
				BRED"%ld"RESET" - 🐼 Panda %d has died.  💀\n",
				ft_time() - panda->data->start_t,
				panda->id + 1
				);
		}
		pthread_mutex_unlock(&panda->data->print_lock);
	}
}
