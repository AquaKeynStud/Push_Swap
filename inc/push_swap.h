/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:48:42 by arocca            #+#    #+#             */
/*   Updated: 2025/02/18 16:05:34 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

/* -- Structures -- */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}				t_stack;

t_stack	*create_stack(void);
t_stack	*init_stack(char **argv, int isLongString);
void	free_stack(t_stack **stack);
int		free_all_stacks(t_stack **a, t_stack **b);

/* -- Parsing -- */
int		check_input(int argc, char **argv);

/* -- Radix Sort -- */
t_node	*get_max(t_stack *stack, int no_index);
void	index_stack(t_stack *stack);
void	radix_sort(t_stack **a, t_stack **b);

/* -- Utils -- */
long	ft_atol(const char *nptr);
int		pass_next_nb(char *s);
int		print(char *s);

/* -- Instructions -- */
void	swap(t_stack **stack, char *s_name);
void	sswap(t_stack **a, t_stack **b);
void	push(t_stack **from, t_stack **to, char *to_name);
void	rotate(t_stack **stack, char *name);
void	rrotate(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack, char *name);
void	rreverse_rotate(t_stack **a, t_stack **b);

#endif