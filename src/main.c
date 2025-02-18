/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:58 by arocca            #+#    #+#             */
/*   Updated: 2025/02/18 16:06:01 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack	*stack)
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

static void	little_sort(t_stack *stack)
{
	t_node	*max;

	if (stack->size == 2 && stack->top->value > stack->bottom->value)
		return (swap(&stack, "sa\n"));
	if (stack->size == 3)
	{
		max = get_max(stack, 0);
		while (!is_sorted(stack))
		{
			if (max == stack->bottom)
				swap(&stack, "sa\n");
			else if (max == stack->top)
				rotate(&stack, "ra\n");
			else
				reverse_rotate(&stack, "rra\n");
		}
	}
	return ;
}

static void	middle_sort(t_stack *a, t_stack *b)
{
	if (a->size == 4)
	{
		while (a->top->index != 0)
			rotate(&a, "ra\n");
		push(&a, &b, "pb\n");
		little_sort(a);
		push(&b, &a, "pa\n");
		return ;
	}
	while (a->size > 3)
	{
		while (a->top->index > 1)
			rotate(&a, "ra\n");
		push(&a, &b, "pb\n");
	}
	little_sort(a);
	push(&b, &a, "pa\n");
	push(&b, &a, "pa\n");
	if (!is_sorted(a))
		swap(&a, "sa\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (check_input(argc, argv))
		return (1);
	a = init_stack(argv + 1, (argc == 2));
	if (is_sorted(a))
		return (free_all_stacks(&a, NULL));
	index_stack(a);
	if (a->size <= 3)
	{
		little_sort(a);
		return (free_all_stacks(&a, NULL));
	}
	b = create_stack();
	if (a->size <= 5)
	{
		middle_sort(a, b);
		return (free_all_stacks(&a, &b));
	}
	radix_sort(&a, &b);
	free_all_stacks(&a, &b);
	return (0);
}
