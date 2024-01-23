/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:38:06 by maserrie          #+#    #+#             */
/*   Updated: 2023/03/31 02:23:36 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../inc/philosophers.h>

void	ft_thread(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->count)
	{
		env->philo[i].l_eat = ft_get_time();
		pthread_create(&env->philo[i].thread, NULL,
			&ft_routine, &env->philo[i]);
		i++;
	}
	i = 0;
	while (!env->die)
	{
		ft_die(&env->philo[i], env);
		i = (i + 1) % env->count;
	}
}
