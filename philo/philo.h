/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 16:37:34 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/09/21 17:02:17 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int					*forks;
	pthread_mutex_t		*fork_mutex;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		dead_mutex;
	long				number_of_philosophers;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				eating_nums;
}				t_data;

typedef struct s_philo
{
	pthread_t				thread;
	long					index;
	long					time_to_die;
	long					time_to_eat;
	long					time_to_sleep;
	long					eating_nums;
	t_data					*data;
}				t_philo;

long			ft_atoi(const char *str);
void			check_numeric(long num);
void			check_input(int ac, char **av);
void			ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo			*ft_lstnew(t_data data, int i);
void			*routine(void *p_philo);
#endif