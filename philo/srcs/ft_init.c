/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:19:34 by maserrie          #+#    #+#             */
/*   Updated: 2023/04/11 22:43:07 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_init(t_env *env)
{
	int	i;

	i = 0;
	env->philo = ft_calloc(env->count, sizeof(t_philo));
	if (!env->philo)
		ft_error(env, "Error: malloc failed", NULL);
	while (i < env->count)
	{
		env->philo[i].id = i;
		env->philo[i].env = env;
		i++;
	}
	env->fork = ft_calloc(sizeof(pthread_mutex_t), env->count);
	if (!env->fork)
		ft_error(env, "Error: malloc failed", NULL);
	i = 0;
	while (i < env->count)
	{
		pthread_mutex_init(&env->fork[i], NULL);
		i++;
	}
	env->start = ft_get_time();
	pthread_mutex_init(&env->print, NULL);
	pthread_mutex_init(&env->eat, NULL);
}
