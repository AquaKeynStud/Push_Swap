/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:58 by arocca            #+#    #+#             */
/*   Updated: 2025/02/06 09:43:35 by keyn             ###   ########.fr       */
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
		while (!sorted_test(stack))
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

void	middle_sort(t_stack *a, t_stack *b)
{
	t_node	*current;
	int		mid_size;

	mid_size = a->size / 2;
	while (a->size > mid_size)
	{
		current = a->top;
		if (current->index < 3)
			push(&a, &b, "pb\n");
		else
			rotate(&a, "ra\n");
	}
	if (!reverse_sorted_test(b))
	{
		little_sort(b);
		swap(&b, "sb\n");
		reverse_rotate(&b, "rrb\n");
	}
	if (!sorted_test(a))
		little_sort(a);
	while (b->size > 0)
		push(&b, &a, "pa\n");
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (check_input(argc, argv))
		return (1);
	a = init_stack(argv + 1, (argc == 2));
	if (sorted_test(a))
		return (free_all_stacks(&a, NULL));
	index_stack(a);
	if (a->size <= 3)
	{
		little_sort(a);
		return (free_all_stacks(&a, NULL));
	}
	b = create_stack();
	if (a->size <= 6)
	{
		middle_sort(a, b);
		return (free_all_stacks(&a, &b));
	}
	radix_sort(&a, &b);
	free_all_stacks(&a, &b);
	return (0);
}
