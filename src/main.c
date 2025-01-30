/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:29:58 by arocca            #+#    #+#             */
/*   Updated: 2025/01/30 17:40:04 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_node	*tmp;

	if (!stack || !(*stack))
		return ;
	while ((*stack) -> top)
	{
		tmp = (*stack) -> top;
		free((*stack) -> top -> next);
		(*stack) -> top = tmp;
	}
	free(*stack);
	*stack = NULL;
	return ;
}

void	create_node_back(t_stack **stack, int n)
{
	t_node	*new_node;

	if (!stack)
		return ;
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (free_stack(stack));
	new_node -> value = n;
	new_node -> index = (*stack) -> size;
	new_node -> next = NULL;
	new_node -> prev = NULL;
	if (!(*stack) -> top)
	{
		(*stack) -> top = new_node;
		(*stack) -> bottom = new_node;
	}
	else
	{
		(*stack) -> bottom -> next = new_node;
		new_node -> prev = (*stack) -> bottom;
		(*stack) -> bottom = new_node;
	}
	(*stack) -> size++;
}

t_stack	*create_stack()
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack -> top = NULL;
	new_stack -> bottom = NULL;
	new_stack -> size = 0;
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
		while (*argv[i])
		{
			create_node_back(&stack, (int)ft_atol(argv[i]));
			if (!pass_next_nb(*argv, i))
					break ;
			i += pass_next_nb(*argv, i);
		}
	}
	else
	{
		while (argv[i])
			create_node_back(&stack, (int)ft_atol(argv[i++]));
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	if (check_input(argc, argv))
		return (1);
	print_stack(init_stack(argv + 1, (argc == 2)), "a");
	return (0);
}
