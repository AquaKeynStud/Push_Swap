/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:39:08 by arocca            #+#    #+#             */
/*   Updated: 2025/02/18 16:05:46 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack, char *name)
{
	t_node	*tmp;

	if (!stack || !(*stack) || !(*stack)->top || (*stack)->size <= 1)
		return ;
	tmp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	(*stack)->bottom->next = tmp;
	tmp->next = NULL;
	(*stack)->bottom = tmp;
	if (name)
		print(name);
	return ;
}

void	reverse_rotate(t_stack **stack, char *name)
{
	t_node	*tmp;
	t_node	*prev_last;

	if (!stack || !(*stack) || !(*stack)->top || (*stack)->size <= 1)
		return ;
	tmp = (*stack)->top;
	prev_last = NULL;
	while (tmp->next)
	{
		prev_last = tmp;
		tmp = tmp->next;
	}
	prev_last->next = NULL;
	(*stack)->bottom = prev_last;
	tmp->next = (*stack)->top;
	(*stack)->top = tmp;
	if (name)
		print(name);
	return ;
}

void	rrotate(t_stack **a, t_stack **b)
{
	if (!(!a || !(*a) || (*a)->size <= 1))
		rotate(a, NULL);
	if (!(!b || !(*b) || (*b)->size <= 1))
		rotate(b, NULL);
	print("rr\n");
}

void	rreverse_rotate(t_stack **a, t_stack **b)
{
	if (!(!a || !(*a) || !(*a)->top || (*a)->size <= 1))
		reverse_rotate(a, NULL);
	if (!(!b || !(*b) || !(*b)->top || (*b)->size <= 1))
		reverse_rotate(b, NULL);
	print("rrr\n");
	return ;
}
