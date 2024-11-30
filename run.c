
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

static bool	ft_take_chopsticks(t_philo *philo)
{
	if (philo->data->stop)
		return (false);
	if (philo->l_chopstick < philo->r_chopstick)
	{
		pthread_mutex_lock(philo->l_chopstick);
		ft_taken_chopstick(philo);
		if (philo->l_chopstick == philo->r_chopstick)
			return (false);
		pthread_mutex_lock(philo->r_chopstick);
		ft_taken_chopstick(philo);
	}
	else
	{
		pthread_mutex_lock(philo->r_chopstick);
		ft_taken_chopstick(philo);
		if (philo->l_chopstick == philo->r_chopstick)
			return (false);
		pthread_mutex_lock(philo->l_chopstick);
		ft_taken_chopstick(philo);
	}
	return (true);
}

bool	ft_eating(t_philo *philo)
{
	if (!ft_take_chopsticks(philo))
		return (false);
	ft_eat(philo);
	philo->last_meal = ft_time() - philo->data->start_t;
	philo->eat_cnt++;
	ft_usleep(philo->data->eat_t);
	pthread_mutex_unlock(philo->l_chopstick);
	pthread_mutex_unlock(philo->r_chopstick);
	return (true);
}

void	ft_dead(t_philo *philo)
{
	if (!philo->data->stop)
	{
		pthread_mutex_lock(&philo->data->print_lock);
		if (!philo->data->stop)
		{
			printf(
				BRED"%ld"RESET" - 🐼 Panda %d has died.  💀\n",
				ft_time() - philo->data->start_t,
				philo->id + 1
				);
		}
		pthread_mutex_unlock(&philo->data->print_lock);
	}
}
