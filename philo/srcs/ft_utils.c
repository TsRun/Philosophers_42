/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 17:32:51 by maserrie          #+#    #+#             */
/*   Updated: 2023/03/31 02:24:15 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t len, size_t size)
{
	void	*mem;
	size_t	temp;
	size_t	i;

	temp = (size_t)(len * size);
	if (len == 0 || size == 0)
		return (malloc(0));
	if (temp / len != size || temp / size != len)
		return (NULL);
	mem = malloc(temp);
	i = 0;
	if (!mem)
		return (NULL);
	while (i < temp)
		((char *)mem)[i++] = '\0';
	return (mem);
}

t_time	ft_get_time(void)
{
	struct timeval	tv;
	t_time			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}
