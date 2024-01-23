/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:24:14 by maserrie          #+#    #+#             */
/*   Updated: 2023/06/23 18:31:31 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

t_time	ft_atoi_ver(char *str, t_env *philo)
{
	int		i;
	t_time	res;

	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((t_time)(res * 10 + str[i] - '0') < res)
			ft_error(philo, "Integer overflow", str);
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != '\0' || i == 0 || str[i - 1] < '0' || str[i - 1] > '9')
		ft_error(philo, "Not a number", str);
	return (res);
}

int	main(int ac, char **av)
{
	t_env	*philo;

	philo = ft_calloc(1, sizeof(t_env));
	if (!philo)
		ft_error(philo, "Error: malloc failed", NULL);
	if (ac != 5 && ac != 6)
		ft_error(philo, "Error the format should be : ./philo [number of philosopher] [time to die] [time to eat] [time to sleep] ([number of eats])", NULL);
	philo->count = ft_atoi_ver(av[1], philo);
	philo->t_die = ft_atoi_ver(av[2], philo);
	philo->t_eat = ft_atoi_ver(av[3], philo);
	philo->t_sleep = ft_atoi_ver(av[4], philo);
	philo->nb_eat = -1;
	if (ac == 6)
		philo->nb_eat = ft_atoi_ver(av[5], philo);
	ft_gest_error(philo);
	ft_init(philo);
	ft_thread(philo);
	ft_end(philo, 0);
	return (0);
}
