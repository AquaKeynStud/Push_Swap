/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:06 by arocca            #+#    #+#             */
/*   Updated: 2025/02/04 18:07:21 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, char *s_name)
{
	t_node	*tmp;

	if (!stack || !(*stack) || !((*stack)->top) || !((*stack)->top->next))
		return ;
	tmp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	tmp->next = (*stack)->top->next;
	(*stack)->top->next = tmp;
	if (s_name)
		print(s_name);
	return ;
}

void	sswap(t_stack **a, t_stack **b)
{
	swap(a, NULL);
	swap(b, NULL);
	print("ss\n");
	return ;
}
