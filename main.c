
#include "inc/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_parser(&data, ac, av))
	{
		printf("Program usage: ");
		printf("./philo <number_of_philosophers> <time_to_die time_to_eat> ");
		printf("<time_to_sleep> [number_of_times_each_philosopher_must_eat]\n");
		return (EXIT_FAILURE);
	}
	data.stop = false;
	ft_init_philos(&data);
	ft_zookeeper(&data);
	ft_exit(&data);
	return (EXIT_SUCCESS);
}