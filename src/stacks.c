/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:20:49 by arocca            #+#    #+#             */
/*   Updated: 2025/02/05 18:15:07 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_node_back(t_stack **stack, int n)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (free_stack(stack));
	new_node->value = n;
	new_node->index = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!(*stack)->top)
	{
		(*stack)->top = new_node;
		(*stack)->bottom = new_node;
	}
	else
	{
		(*stack)->bottom->next = new_node;
		new_node->prev = (*stack)->bottom;
		(*stack)->bottom = new_node;
	}
	(*stack)->size++;
}

void	free_stack(t_stack **stack)
{
	t_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while ((*stack)->top)
	{
		tmp = (*stack)->top->next;
		free((*stack)->top);
		(*stack)->top = tmp;
	}
	free(*stack);
	*stack = NULL;
	return ;
}

int	free_all_stacks(t_stack **a, t_stack **b)
{
	if (a && (*a))
		free_stack(a);
	if (b && (*b))
		free_stack(b);
	return (0);
}

t_stack	*create_stack(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->top = NULL;
	new_stack->bottom = NULL;
	new_stack->size = 0;
	return (new_stack);
}

t_stack	*init_stack(char **argv, int isLongString)
{
	t_stack	*stack;
	int		i;

	i = 0;
	stack = create_stack();
	if (isLongString)
	{
		while (*argv[0] == ' ')
			argv[0]++;
		while (*argv[0])
		{
			create_node_back(&stack, (int)ft_atol(argv[0]));
			argv[0] += pass_next_nb(argv[0]);
		}
	}
	else
	{
		while (argv[i])
			create_node_back(&stack, (int)ft_atol(argv[i++]));
	}
	return (stack);
}
