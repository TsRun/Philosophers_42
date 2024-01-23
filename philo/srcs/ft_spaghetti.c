/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spaghetti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:26:30 by maserrie          #+#    #+#             */
/*   Updated: 2023/04/11 22:47:23 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	*ft_routine(void *philo)
{
	t_philo	*philo2;

	philo2 = (t_philo *)philo;
	if (philo2->env->count == 1)
	{
		ft_print(philo, 1, "has taken a fork");
		return (NULL);
	}
	if (philo2->id % 2 == 1)
		usleep(philo2->env->t_eat / 2 * 1000);
	while (!philo2->env->die)
	{
		ft_eat(philo2, philo2->env);
		if (philo2->count_eat == philo2->env->nb_eat || philo2->env->die)
			break ;
		ft_sleep(philo2, philo2->env);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo, t_env *env)
{
	if (env->die)
		return ;
	pthread_mutex_lock(&env->fork[philo->id]);
	ft_print(philo, 1, "has taken a fork");
	pthread_mutex_lock(&env->fork[(philo->id + 1) % env->count]);
	ft_print(philo, 1, "has taken a fork");
	ft_print(philo, 0, "is eating");
	pthread_mutex_lock(&env->eat);
	philo->l_eat = ft_get_time();
	pthread_mutex_unlock(&env->eat);
	while (env->t_eat > ft_get_time() - philo->l_eat)
		usleep(10);
	pthread_mutex_unlock(&env->fork[philo->id]);
	pthread_mutex_unlock(&env->fork[(philo->id + 1) % env->count]);
	philo->count_eat++;
	pthread_mutex_lock(&env->eat);
	if (env->nb_eat == philo->count_eat)
		env->count_eat++;
	if (env->count <= env->count_eat)
		env->die = 1;
	pthread_mutex_unlock(&env->eat);
}

void	ft_sleep(t_philo *philo, t_env *env)
{
	t_time	time;

	ft_print(philo, 2, "is sleeping");
	time = ft_get_time();
	while (env->t_sleep > ft_get_time() - time)
	{
		usleep(10);
		if (env->die)
			break ;
	}
	ft_print(philo, 4, "is thinking");
}

void	ft_die(t_philo *philo, t_env *env)
{
	pthread_mutex_lock(&env->eat);
	if (env->t_die <= ft_get_time() - philo->l_eat && !env->die)
	{
		env->die = 1;
		pthread_mutex_lock(&env->print);
		printf("%s%ld %s", GREEN, ft_get_time() - philo->env->start, "💀");
		printf(" %d %s\n%s", philo->id + 1, "died", DEF_COLOR);
		pthread_mutex_unlock(&env->print);
	}
	pthread_mutex_unlock(&env->eat);
}
