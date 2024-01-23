/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maserrie <maserrie@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 10:20:51 by maserrie          #+#    #+#             */
/*   Updated: 2023/03/31 06:18:04 by maserrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define DEF_COLOR	"\033[0;39m"
# define ORANGE	"\033[0;33m"
# define GRAY	"\033[0;90m"
# define RED	"\033[0;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN		"\033[0;96m"
# define WHITE		"\033[0;97m"

struct					s_env;

typedef unsigned long	t_time;

typedef struct s_philo
{
	t_time			l_eat;
	int				id;
	int				count_eat;
	struct s_env	*env;
	pthread_t		thread;
}	t_philo;

typedef struct s_env
{
	int				count;
	int				die;
	t_time			t_die;
	t_time			t_eat;
	t_time			t_sleep;
	int				nb_eat;
	t_time			start;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	eat;
	t_philo			*philo;
	int				count_eat;
}	t_env;

size_t	ft_strlen(const char *str);

void	ft_puterror(char *str);

void	*ft_calloc(size_t len, size_t size);

void	ft_error(t_env *philo, char *str, char *str2);

void	ft_gest_error(t_env *philo);

void	ft_end(t_env *philo, int i);

t_time	ft_get_time(void);

void	ft_init(t_env *env);

void	*ft_routine(void *philo);

void	ft_thread(t_env *env);

void	ft_die(t_philo *philo, t_env *env);

void	ft_print(t_philo *philo, int i, char *str2);

void	ft_eat(t_philo *philo, t_env *env);

void	ft_sleep(t_philo *philo, t_env *env);

#endif
