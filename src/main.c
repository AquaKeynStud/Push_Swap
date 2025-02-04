/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:58 by arocca            #+#    #+#             */
/*   Updated: 2025/02/04 11:46:04 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	if (check_input(argc, argv))
		return (1);
	a = init_stack(argv + 1, (argc == 2));
	index_stack(a);
	b = create_stack();
	radix_sort(&a, &b);
	print_stack(a, "a");
	return (0);
}
