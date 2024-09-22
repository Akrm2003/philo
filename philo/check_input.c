/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:15:02 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/09/21 16:43:17 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_numeric(long num)
{
	if (num < 0 || num == 3147483647)
	{
		write(1, "Error in input\n", 15);
		exit(1);
	}
}
void	check_input(int ac, char **av)
{
	long	input[5];
	int		i;

	i = -1;
	input[0] = ft_atoi(av[1]);
	input[1] = ft_atoi(av[2]);
	input[2] = ft_atoi(av[3]);
	input[3] = ft_atoi(av[4]);
	if (ac == 6)
		input[4] = ft_atoi(av[5]);
	else
		input[4] = -1;
	if (input[0] < 1 || input[1] <= 0 || input[2] <= 0 || input[3] <= 0)
		write(2, "Error in input's value\n", 23), exit(1);
	if (ac == 6 && input[4] < 1)
		write(2, "Error in input's value\n", 23), exit(1);
	while (++i < ac - 1)
		check_numeric(input[i]);
}
