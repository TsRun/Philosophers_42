/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaghetti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:26:30 by maserrie          #+#    #+#             */
/*   Updated: 2023/03/31 15:09:54 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*ft_routine(void *philo)
{
	t_philo		*philo2;
	pthread_t	thread;

	pthread_create(&thread, NULL, ft_die, philo);
	pthread_detach(thread);
	philo2 = (t_philo *)philo;
	while (!philo2->env->die)
	{
		ft_fork(philo2, philo2->env);
		ft_eat(philo2, philo2->env);
		ft_sleep(philo2, philo2->env);
	}
	return (NULL);
}

void	ft_fork(t_philo *philo, t_env *env)
{
	sem_wait(env->forks);
	ft_print(philo, 1, "has taken a fork");
	sem_wait(env->forks);
	ft_print(philo, 1, "has taken a fork");
}

void	ft_eat(t_philo *philo, t_env *env)
{
	ft_print(philo, 0, "is eating");
	sem_wait(env->eat);
	philo->l_eat = ft_get_time();
	sem_post(env->eat);
	while (env->t_eat > ft_get_time() - philo->l_eat)
		usleep(10);
	sem_post(env->forks);
	sem_post(env->forks);
	sem_wait(env->eat);
	philo->count_eat++;
	sem_post(env->eat);
}

void	ft_sleep(t_philo *philo, t_env *env)
{
	t_time	time;

	ft_print(philo, 2, "is sleeping");
	time = ft_get_time();
	while (env->t_sleep > ft_get_time() - time)
		usleep(10);
	ft_print(philo, 4, "is thinking");
}

void	*ft_die(void *philo2)
{
	t_philo	*philo;
	t_env	*env;

	philo = (t_philo *)philo2;
	env = philo->env;
	while (1)
	{
		sem_wait(env->eat);
		if (env->t_die <= ft_get_time() - philo->l_eat)
		{
			ft_print(philo, 3, "died");
			sem_post(env->end);
			break ;
		}
		sem_post(env->eat);
		sem_wait(env->eat);
		if (philo->count_eat == env->nb_eat)
		{
			sem_post(env->all_eat);
			sem_post(env->eat);
			exit(0);
		}
		sem_post(env->eat);
	}
	return (NULL);
}
