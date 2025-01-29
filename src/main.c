/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:58 by arocca            #+#    #+#             */
/*   Updated: 2025/01/29 15:20:32 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "push_swap.h"

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

int	check_string(char *s)
{
	int		n;
	int		temp;
	size_t	i;

	while (*s)
	{
		n = ft_atoi(s);
		s += c_d(n);
		i = 0;
		while (s[i])
		{
			temp = ft_atoi(&s[i]);
			if (n == temp)
				return (print("Error\n"));
			else
				i += c_d(temp);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 2)
		check_string(argv[argc - 1]); // Fonction pour check une grande chaine regroupant les arguments
	//else
		//check_args(*argv[1]); // Fonction pour check les arguments envoyés à la suite
}

// int	check_string(char *s)
// {
// 	unsigned int	i;
// 	int				**tab;
// 	int				**temptab;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != ' ' && (s[i] < '0' || s[i] > '9'))
// 			return (print(1, "Error\n"));
// 	}
// 	tab = (int **)malloc(sizeof(int *) + 1);
// 	if (!tab)
// 		return (1);
// 	tab[0] = ft_atoi(*s);
// 	tab[1] = 0;
// 	s += c_d(tab[0]);
// 	while (*s)
// 	{
// 		temptab = (int **)malloc(sizeof(tab) + sizeof(int *) + 1);
// 		ft_memove
// 	}
// }