/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:58 by arocca            #+#    #+#             */
/*   Updated: 2025/02/03 15:03:53 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	if (check_input(argc, argv))
		return (1);
	a = init_stack(argv + 1, (argc == 2));
	print_stack(a, "a");
	swap(&a, "sa\n");
	print_stack(a, "a");
	return (0);
}
