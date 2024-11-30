/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:40:28 by ssottori          #+#    #+#             */
/*   Updated: 2024/11/30 16:40:30 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

bool	ft_full(t_data *data)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < data->nop)
		if (data->pandas[i].full)
			count++;
	if (count == data->nop)
		return (true);
	else
		return (false);
}

long	ft_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(long time)
{
	long	then;

	then = ft_time();
	while ((ft_time() - then) < time)
		usleep(100);
}

void	ft_write(t_philo *panda, const char *msg)
{
	if (!panda->data->stop)
	{
		pthread_mutex_lock(&panda->data->print_lock);
		if (!panda->data->stop)
		{
			printf(
				BBLU"%ld"RESET" - 🐼 Panda %d %s\n",
				ft_time() - panda->data->start_t,
				panda->id + 1, msg);
		}
		pthread_mutex_unlock(&panda->data->print_lock);
	}
}

int	ft_error(t_data *data, const char *msg)
{
	printf(BRED"%s"RESET"\n", msg);
	if (data)
		ft_exit(data);
	return (1);
}