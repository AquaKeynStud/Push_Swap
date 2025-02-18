/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:04:01 by keyn              #+#    #+#             */
/*   Updated: 2025/02/18 16:06:06 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_max(t_stack *stack, int no_index)
{
	t_node	*max;
	t_node	*current;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	max = NULL;
	while (current)
	{
		if (no_index && current->index == -1)
		{
			if (!max || current->value > max->value)
				max = current;
		}
		else if (!no_index)
		{
			if (!max || current->value > max->value)
				max = current;
		}
		current = current->next;
	}
	return (max);
}

static int	get_num_bits(int max)
{
	int	bits;

	bits = 0;
	while (max >> bits)
		bits++;
	return (bits);
}

void	index_stack(t_stack *stack)
{
	int		index;
	t_node	*max;

	index = stack->size - 1;
	while (index >= 0)
	{
		max = get_max(stack, 1);
		if (max)
			max->index = index;
		index--;
	}
	return ;
}

static void	manage_index(t_stack **a, t_stack **b, int i)
{
	int		size;
	int		j;

	j = 0;
	size = (*a)->size;
	while (j < size)
	{
		if ((((*a)->top->index >> i) & 1) == 0)
			push(a, b, "pb\n");
		else
			rotate(a, "ra\n");
		j++;
	}
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		num_bits;
	int		i;
	int		size;
	int		j;

	num_bits = get_num_bits(get_max(*a, 0)->index);
	i = 0;
	while (i < num_bits)
	{
		manage_index(a, b, i);
		j = 0;
		size = (*b)->size;
		while (j < size)
		{
			if (((((*b)->top->index >> i) & 1) == 0))
				rotate(b, "rb\n");
			else
				push(b, a, "pa\n");
			j++;
		}
		i++;
	}
	while ((*b) && (*b)->size > 0)
		push(b, a, "pa\n");
}
