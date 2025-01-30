/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:00:31 by keyn              #+#    #+#             */
/*   Updated: 2025/01/30 10:09:37 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

int	check_no_char(char *s)
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

int	parse_input_string(char *s)
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
			if (n == temp || n > INT_MAX || temp > INT_MIN)
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

int	parse_input_args(char **s)
{
	long	n;
	long	temp;
	int		i;
	int		j;

	i = 0;
	while (s[i])
	{
		if (check_no_char(s[i]))
			return (1);
		n = ft_atol(s[i]);
		j = i + 1;
		while (s[j])
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

int	check_input(int argc, char **argv)
{
	if (argc == 2)
	{
		if (check_no_char(argv[1]) || parse_input_string(argv[1]))
			return (print("Error\n"));
	}
	else if (argc > 2)
	{
		if (parse_input_args(argv + 1))
			return (print("Error\n"));
	}
	else
		return (0);
	return (0);
}