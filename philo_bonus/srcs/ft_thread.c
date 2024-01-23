/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:38:06 by maserrie          #+#    #+#             */
/*   Updated: 2023/03/31 15:07:24 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_thread(t_env *env)
{
	int	i;

	i = 0;
	env->start = ft_get_time();
	while (i < env->count)
	{
		env->philo[i].l_eat = ft_get_time();
		env->philo[i].pid = fork();
		if (env->philo[i].pid == 0)
		{
			ft_routine(&env->philo[i]);
			exit(0);
		}
		if (env->philo[i].pid < 0)
			ft_error(env, "Fork error", NULL);
		i++;
		usleep(100);
	}
	ft_wait(env);
	sem_wait(env->end);
}

void	ft_wait(t_env *env)
{
	int	i;

	i = 0;
	env->pid = fork();
	if (env->pid == 0)
	{
		while (i++ < env->count)
			sem_wait(env->all_eat);
		sem_post(env->end);
		exit(0);
	}
}
