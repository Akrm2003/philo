/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asid-ahm <asid-ahm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:51:37 by asid-ahm          #+#    #+#             */
/*   Updated: 2024/09/18 21:19:31 by asid-ahm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	result(const char *str, size_t i, int n)
{
	unsigned long long	k;

	k = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] && k < 2147483647)
		k = k * 10 + str[i++] - '0';
	if (str[i] && (str[i] > '9' || str[i] < '0'))
		return (3147483647);
	if (k > 2147483647 && n == 1)
		return (3147483647);
	return (k);
}

long	ft_atoi(const char *str)
{
	size_t	i;
	size_t	x;
	int		n;

	x = 0;
	i = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			return (3147483647);
		i++;
		x++;
	}
	while (str[i] == '0' && str[i])
	{
		i++;
		x++;
	}
	return (n * result(str, i, n));
}
