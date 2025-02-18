/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:39:20 by arocca            #+#    #+#             */
/*   Updated: 2025/02/18 16:06:18 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <unistd.h>

long	ft_atol(const char *nptr)
{
	unsigned long long	res;
	long				sign;

	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr++ - '0');
		if (res > 2147483648 || (res > 2147483647 && sign > 0))
			return (LONG_MAX);
	}
	return (((long)res) * sign);
}

int	pass_next_nb(char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		i++;
	while (s[i] && (s[i] == ' ' || s[i] == '-' || s[i] == '+'))
		i++;
	return (i);
}

int	print(char *s)
{
	int	i;
	int	success;

	i = 0;
	while (s[i])
		i++;
	if (!s)
		return (-1);
	success = write(1, s, i);
	if (success == -1)
		return (-1);
	return (1);
}
