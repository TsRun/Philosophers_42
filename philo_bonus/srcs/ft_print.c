/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:33:49 by maserrie          #+#    #+#             */
/*   Updated: 2023/03/31 13:34:49 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	ft_puterror(char *str)
{
	if (!str)
		return ;
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

void	ft_print(t_philo *philo, int i, char *str2)
{
	char	*str;

	if (philo->env->die)
		return ;
	if (i == 0)
		str = "🍝";
	if (i == 1)
		str = "🍴";
	if (i == 2)
		str = "💤";
	if (i == 3)
		str = "💀";
	if (i == 4)
		str = "🤔";
	sem_wait(philo->env->print);
	printf("%s%ld %s", GREEN, ft_get_time() - philo->env->start, str);
	printf(" %d %s\n%s", philo->id + 1, str2, DEF_COLOR);
	if (i != 3)
		sem_post(philo->env->print);
}
