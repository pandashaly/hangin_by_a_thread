/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:40:17 by ssottori          #+#    #+#             */
/*   Updated: 2024/11/30 16:40:18 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

void	ft_taken_chopstick(t_philo *panda)
{
	ft_write(panda, CHOP);
}

void	ft_eat(t_philo *panda)
{
	ft_write(panda, EAT);
}

void	ft_nap(t_philo *panda)
{
	ft_write(panda, NAP);
}

void	ft_think(t_philo *panda)
{
	ft_write(panda, THINK);
}

void	*ft_routine(void *p)
{
	t_philo	*panda;

	panda = (t_philo *)p;
	if (panda->id % 2)
		ft_usleep(100);
	while (true)
	{
		if (!ft_eating(panda) || panda->full || panda->data->stop)
			break ;
		ft_nap(panda);
		ft_usleep(panda->data->nap_t);
		ft_think(panda);
	}
	if (panda->l_chopstick == panda->r_chopstick)
		pthread_mutex_unlock(panda->l_chopstick);
	return (NULL);
}
