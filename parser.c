/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssottori <ssottori@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:17:43 by otodd             #+#    #+#             */
/*   Updated: 2024/11/30 11:13:59 by ssottori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/philo.h"

bool	ft_parse_args(t_data *data, int ac, char **av)
{
	if (ac == 1 || ac > 6)
		return (false);
	if (!ft_ischeck_str(av[1], ft_isdigit))
		return (false);
	data->nop = ft_atoi(av[1]);
	if (!data->nop)
		return (false);
	if (!ft_ischeck_str(av[2], ft_isdigit))
		return (false);
	data->life_t = ft_atoi(av[2]);
	if (!ft_ischeck_str(av[3], ft_isdigit))
		return (false);
	data->eat_t = ft_atoi(av[3]);
	if (!ft_ischeck_str(av[4], ft_isdigit))
		return (false);
	data->nap_t = ft_atoi(av[4]);
	if (ac == 6)
	{
		if (!ft_ischeck_str(av[5], ft_isdigit))
			return (false);
		data->must_eat_t = ft_atoi(av[5]);
	}
	else
		data->must_eat_t = -1;
	return (true);
}

int	ft_atoi(const char *nptr)
{
	int		value;
	int		operation;
	char	*c;

	c = (char *)nptr;
	operation = 1;
	value = 0;
	while ((*c == ' ') || (*c == '\t')
		|| (*c == '\v') || (*c == '\r') || (*c == '\n') || (*c == '\f'))
		c++;
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			operation *= -1;
		c++;
	}
	while (*c >= '0' && *c <= '9')
		value = (value * 10) + (*c++ - '0');
	return (value * operation);
}

int	ft_ischeck_str(char *str, int (*f)(int))
{
	while (*str)
		if (!f(*str++))
			return (0);
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}
