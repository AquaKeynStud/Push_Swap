/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:04:01 by keyn              #+#    #+#             */
/*   Updated: 2025/02/04 12:18:23 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_max(t_stack *stack, int no_index)
{
	t_node	*max;
	t_node	*current;

	if (!stack || !stack -> top)
		return (NULL);
	current = stack -> top;
	max = current;
	while (current)
	{
		if (current -> value > max -> value)
		{
			if ((no_index && current -> index == -1) || (!no_index))
				max = current;
		}
		current = current -> next;
	}
	return (max);
}

int	get_num_bits(int max)
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

	index = stack -> size - 1;
	while (index >= 0)
	{
		max = get_max(stack, 1);
		if (max)
			max -> index = index;
		index--;
	}
	return ;
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int	num_bits;
	int	size;
	int	i;
	int	j;
	t_node	*current;

	print_stack(*a, "a");
	num_bits = get_num_bits(get_max(*a, 0) -> index);
	i = 0;
	while (i < num_bits)
	{
		j = 0;
		size = (*a) -> size;
		while (j < size)
		{
			current = (*a)->top;
			if (((current->index >> i) & 1) == 0)
				push(a, b, "pb\n");
			else
				rotate(a, "ra\n");
			j++;
		}
		while ((*b) && (*b)->size > 0)
			push(b, a, "pa\n");
		i++;
	}
	return ;
}