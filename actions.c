/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:18 by otodd             #+#    #+#             */
/*   Updated: 2024/11/30 11:35:42 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	ft_taken_chopstick(t_philo *philo)
{
	ft_write(philo, CHOP);
}

void	ft_eat(t_philo *philo)
{
	ft_write(philo, EAT);
}

void	ft_nap(t_philo *philo)
{
	ft_write(philo, NAP);
}

void	ft_think(t_philo *philo)
{
	ft_write(philo, THINK);
}

void	ft_dead(t_philo *philo)
{
	if (!philo->data->stop)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		if (!philo->data->stop)
		{
			printf(
				BRED"%ld"RESET" - Panda %d has died\n",
				ft_time() - philo->data->start_t,
				philo->id + 1
				);
		}
		pthread_mutex_unlock(&philo->data->print_lock);
	}
}
