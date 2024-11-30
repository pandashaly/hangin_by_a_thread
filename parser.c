/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:40:09 by ssottori          #+#    #+#             */
/*   Updated: 2024/11/30 16:40:11 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

int	ft_parser(t_data *data, int ac, char **av)
{
	if (ac == 1 || ac > 6)
		return (0);
	if (ft_arg_check(av))
		return (0);
	data->nop = ft_atoi(av[1]);
	if (!data->nop)
		return (0);
	data->life_t = ft_atoi(av[2]);
	data->eat_t = ft_atoi(av[3]);
	data->nap_t = ft_atoi(av[4]);
	if (ac == 6)
		data->must_eat_t = ft_atoi(av[5]);
	else
		data->must_eat_t = -1;
	if (data->life_t <= 0
		|| data->eat_t <= 0 || data->nap_t <= 0
		|| (ac == 6 && data->must_eat_t <= 0))
		return (0);
	return (ft_limits(data));
}

int	ft_atoi(const char *nptr)
{
	int		v;
	int		o;
	char	*c;

	c = (char *)nptr;
	o = 1;
	v = 0;
	while (*c == ' ' || (*c >= 9 && *c <= 13))
		c++;
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			o *= -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
		v = (v * 10) + (*c++ - '0');
	return (v * o);
}

int	ft_limits(t_data *data)
{
	if (data->nop > MAX_PHILOS || data->nop <= 0)
	{
		ft_error(data, MAX_P_ERR);
		return (0);
	}
	if (data->life_t > MAX_TIME
		|| data->eat_t > MAX_TIME || data->nap_t > MAX_TIME)
	{
		ft_error(data, MAX_T_ERR);
		return (0);
	}
	if (data->must_eat_t < -1)
	{
		ft_error(data, MET_ERR);
		return (0);
	}
	return (1);
}

int	ft_arg_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				j++;
				continue ;
			}
			if ((av[i][j] < '0' || av[i][j] > '9'))
				return (ft_error(NULL, WRONG_AV));
			j++;
		}
		i++;
	}
	return (0);
}
