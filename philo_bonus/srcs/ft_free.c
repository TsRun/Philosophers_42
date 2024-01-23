/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:30:02 by maserrie          #+#    #+#             */
/*   Updated: 2023/04/11 22:50:06 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_free(t_env *philo)
{
	int	i;

	usleep(1000);
	if (!philo)
		return ;
	i = -1;
	if (philo->philo)
		while (++i < philo->count)
			if (philo->philo[i].pid != 0)
				kill(philo->philo[i].pid, SIGKILL);
	kill(philo->pid, SIGKILL);
	if (philo->philo)
		free(philo->philo);
	if (philo->forks)
		sem_close(philo->forks);
	if (philo->print)
		sem_close(philo->print);
	if (philo->eat)
		sem_close(philo->eat);
	if (philo->end)
		sem_close(philo->end);
	if (philo->all_eat)
		sem_close(philo->all_eat);
	free(philo);
}

void	ft_end(t_env *philo, int i)
{
	ft_free(philo);
	exit(i);
}

void	ft_error(t_env *philo, char *str, char *str2)
{
	ft_puterror(str2);
	ft_puterror(str);
	ft_end(philo, 1);
}

void	ft_gest_error(t_env *env)
{
	if (env->count < 1)
		ft_error(env, "number of philosophers must be at least 1", "Error: ");
	if (env->t_die < 60)
		ft_error(env, "time to die must be at least 60 ms", "Error: ");
	if (env->t_eat < 60)
		ft_error(env, "time to eat must be at least 60 ms", "Error: ");
	if (env->t_sleep < 60)
		ft_error(env, "time to sleep must be at least 60 ms", "Error: ");
	if (env->nb_eat != -1 && env->nb_eat < 1)
	{
		ft_error(env, "number of times each philosopher\
must eat > 1", "Error: ");
	}
}
