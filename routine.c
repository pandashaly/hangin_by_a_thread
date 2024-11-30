
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

void	*ft_routine(void *p)
{
	t_philo	*philo;

	philo = (t_philo *)p;
	if (philo->id % 2)
		ft_usleep(100);
	while (true)
	{
		if (!ft_eating(philo) || philo->full || philo->data->stop)
			break ;
		ft_nap(philo);
		ft_usleep(philo->data->nap_t);
		ft_think(philo);
	}
	if (philo->l_chopstick == philo->r_chopstick)
		pthread_mutex_unlock(philo->l_chopstick);
	return (NULL);
}
