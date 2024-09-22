/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 13:44:46 by louisalah         #+#    #+#             */
/*   Updated: 2024/09/21 16:45:50 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	print_data(t_data data)
// {
// 	printf("number_of_philosophers: %d\n", data.number_of_philosophers);
// 	printf("time_to_die: %d\n", data.time_to_die);
// 	printf("time_to_eat: %d\n", data.time_to_eat);
// 	printf("time_to_sleep: %d\n", data.time_to_sleep);
// 	printf("eating_nums: %d\n", data.eating_nums);
// }

void	init_data(t_data *data, char **av, int ac)
{
	int	i;

	i = -1;
	data->number_of_philosophers = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->eating_nums = ft_atoi(av[5]);
	else
		data->eating_nums = -1;
	data->forks = (int *)malloc(sizeof(int) * data->number_of_philosophers);
	pthread_mutex_init(&data->print_mutex, NULL);
	pthread_mutex_init(&data->dead_mutex, NULL);
	data->fork_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->number_of_philosophers);
	while (++i < data->number_of_philosophers)
	{
		data->forks[i] = 0;
		pthread_mutex_init(&data->fork_mutex[i], NULL);
	}
}

t_philo	**init_philo(t_data *data)
{
	int		i;
	t_philo	**philo;

	i = -1;
	philo = (t_philo **)malloc(sizeof(t_philo *)
			* data->number_of_philosophers);
	while (++i < data->number_of_philosophers)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->index = i;
		philo[i]->time_to_die = data->time_to_die;
		philo[i]->time_to_eat = data->time_to_eat;
		philo[i]->time_to_sleep = data->time_to_sleep;
		philo[i]->eating_nums = data->eating_nums;
		philo[i]->data = data;
	}
	return (philo);
}

int	main(int ac, char **av)
{
	t_data		data;
	t_philo		**philo;
	int			i;

	i = -1;
	if (ac > 6 || ac < 5)
		(write(2, "Error: Wrong number of arguments\n", 33), exit(1));
	check_input(ac, av);
	init_data(&data, av, ac);
	philo = init_philo(&data);
	while (++i < data.number_of_philosophers)
		pthread_create(&philo[i]->thread, NULL, &routine, (void *)philo[i]);
	i = -1;
	while (++i < data.number_of_philosophers)
		pthread_join(philo[i]->thread, NULL);
}
