/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:58 by arocca            #+#    #+#             */
/*   Updated: 2025/02/04 16:41:05 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_test(t_stack	*stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	reverse_sorted_test(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value < current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	little_sort(t_stack *stack)
{
	t_node	*max;

	if (stack->size == 2 && stack->top->value > stack->bottom->value)
		return (swap(&stack, "sa\n"));
	if (stack->size == 3)
	{
		max = get_max(stack, 0);
		if (max == stack -> bottom)
			swap(&stack, "sa\n");
		else if (max == stack -> top)
			rotate(&stack, "ra\n");
		else
			reverse_rotate(&stack, "rra\n");
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	if (check_input(argc, argv))
		return (free_all_stacks(&a, NULL, 1));
	a = init_stack(argv + 1, (argc == 2));
	if (sorted_test(a))
		return (free_all_stacks(&a, NULL, 0));
	index_stack(a);
	print_stack(a, "a");
	b = create_stack();
	if (a -> size <= 3)
	{
		while (!sorted_test(a))
			little_sort(a);
		print_stack(a, "a");
		return (free_all_stacks(&a, &b, 0));
	}
	radix_sort(&a, &b);
	print_stack(a, "a");
	free_all_stacks(&a, &b, 0);
	return (0);
}
