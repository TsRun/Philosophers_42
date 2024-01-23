/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:19:34 by maserrie          #+#    #+#             */
/*   Updated: 2023/03/31 15:03:11 by maserrie         ###   ########.fr       */
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
	sem_unlink("/forks");
	sem_unlink("/eat");
	sem_unlink("/print");
	sem_unlink("/end");
	sem_unlink("/all_eat");
	env->forks = sem_open("/forks", O_CREAT, 0644, (int)env->count);
	env->print = sem_open("/print", O_CREAT, 0644, 1);
	env->eat = sem_open("/eat", O_CREAT, 0644, 1);
	env->end = sem_open("/end", O_CREAT, 0644, 0);
	env->all_eat = sem_open("/all_eat", O_CREAT, 0644, 0);
}
