/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:58 by arocca            #+#    #+#             */
/*   Updated: 2025/01/29 19:01:09 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "push_swap.h"

static int	check_double(char *s)
{
	long	n;
	long	temp;
	int		i;

	while (*s)
	{
		n = ft_atol(s);
		s += pass_next_nb(s, 0);
		i = 0;
		while (s[i])
		{
			temp = ft_atol(&s[i]);
			if (n == temp || temp > INT_MAX)
				return (1);
			else
			{
				if (!pass_next_nb(s, i))
					break ;
				i += pass_next_nb(s, i);
			}
		}
	}
	return (0);
}

static int	check_char(char *s)
{
	while (*s)
	{
		if ((*s >= '0' && *s <= '9') || *s == ' ' || *s == '-' || *s == '+')
		{
			while ((*s >= '0' && *s <= '9') || *s == ' ')
				s++;
			if (*s == '-' || *s == '+')
			{
				s++;
				if (*s == '+' || *s == '-' || *s < '0' || *s > '9')
					return (1);
			}
		}
		else
			return (1);
	}
	return (0);
}

static int	check_args(char **s)
{
	long	n;
	long	temp;
	int		i;
	int		j;

	i = 0;
	j = 1;
	while (*s[i])
	{
		if (check_char(s[i]))
			return (1);
		n = ft_atol(s[i]);
		while (*s[j])
		{
			temp = ft_atol(s[j]);
			if (n == temp || n > INT_MAX || temp > INT_MAX)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_char(argv[1]) || check_double(argv[1]))
			return (print("Error\n"));
	}
	else if (argc > 2)
	{
		if (check_args(argv + 1))
			return (print("Error\n"));
	}
	else
		return (0);
}
