/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:48:42 by arocca            #+#    #+#             */
/*   Updated: 2025/02/06 16:46:52 by arocca           ###   ########.fr       */
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
void	create_node_back(t_stack **stack, int n);
void	free_stack(t_stack **stack);
int		free_all_stacks(t_stack **a, t_stack **b);

/* -- Sources -- */
int		check_input(int argc, char **argv);
int		sorted_test(t_stack	*stack);

t_node	*get_max(t_stack *stack, int no_index);
int		get_num_bits(int max);
void	index_stack(t_stack *stack);
void	radix_sort(t_stack **a, t_stack **b);

/* -- Utils -- */
long	ft_atol(const char *nptr);
int		pass_next_nb(char *s);
int		print(char *s);

/* -- Instructions -- */
void	swap(t_stack **stack, char *s_name);
void	push(t_stack **from, t_stack **to, char *to_name);
void	rotate(t_stack **stack, char *name);
void	reverse_rotate(t_stack **stack, char *name);
void	rrotate(t_stack **a, t_stack **b);
void	rreverse_rotate(t_stack **a, t_stack **b);
void	sswap(t_stack **a, t_stack **b);

#endif