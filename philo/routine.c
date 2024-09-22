/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:45:15 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/09/21 17:56:16 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

void	ft_usleep(long time)
{
	long	start;
	long	end;

	start = get_time();
	end = start + time;
	while (get_time() < end)
		usleep(100);
}

void	*routine(void *p_philo)
{
	int		left;
	int		right;
	int		status;
	t_philo	*philo;

	philo = (t_philo *)p_philo;
	while (1)
	{
		philo->eating_nums--;
		if (philo->eating_nums != -2 && philo->eating_nums == 0)
			break ;
		if (philo->index == philo->data->number_of_philosophers - 1)
		{
			left = philo->index;
			right = 0;
		}
		else
		{
			left = philo->index;
			right = philo->index + 1;
		}
		if (philo->data->forks[left] == 0 && philo->data->forks[right] == 0)
		{
			pthread_mutex_lock(&philo->data->fork_mutex[left]);
			philo->data->forks[left] = 1;
			pthread_mutex_lock(&philo->data->fork_mutex[right]);
			philo->data->forks[right] = 1;
			pthread_mutex_lock(&philo->data->print_mutex);
			printf("%ld has taken a fork\n", philo->index + 1);
			pthread_mutex_unlock(&philo->data->print_mutex);
			pthread_mutex_lock(&philo->data->print_mutex);
			printf("%ld has taken a fork\n", philo->index + 1);
			pthread_mutex_unlock(&philo->data->print_mutex);
			pthread_mutex_lock(&philo->data->print_mutex);
			printf("%ld is eating\n", philo->index + 1);
			pthread_mutex_unlock(&philo->data->print_mutex);
			usleep(philo->time_to_eat * 1000);
			pthread_mutex_unlock(&philo->data->fork_mutex[left]);
			philo->data->forks[left] = 0;
			pthread_mutex_unlock(&philo->data->fork_mutex[right]);
			philo->data->forks[right] = 0;
			pthread_mutex_lock(&philo->data->print_mutex);
			printf("%ld is sleeping\n", philo->index + 1);
			pthread_mutex_unlock(&philo->data->print_mutex);
			usleep(philo->time_to_sleep * 1000);
			pthread_mutex_lock(&philo->data->print_mutex);
			printf("%ld is thinking\n", philo->index + 1);
			pthread_mutex_unlock(&philo->data->print_mutex);
			break ;
		}
	}
	return (NULL);
}
