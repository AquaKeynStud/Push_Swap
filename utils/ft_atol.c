/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:39:20 by arocca            #+#    #+#             */
/*   Updated: 2025/01/30 16:25:48 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

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
