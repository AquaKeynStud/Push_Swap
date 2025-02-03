/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arocca <arocca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:48:42 by arocca            #+#    #+#             */
/*   Updated: 2025/02/03 16:45:01 by arocca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

#include <stdio.h>

/* -- Structures -- */
typedef struct	s_node
{
	int				value;
	int				index;
	struct	s_node	*next;
	struct	s_node	*prev;
}				t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}				t_stack;

/* -- Utils -- */
long	ft_atol(const char *nptr);
int		pass_next_nb(char *s);
int		print(char *s);

/* -- Sources -- */
int	check_no_char(char *s);
int	parse_input_string(char *s);
int	parse_input_args(char **s);
int	check_input(int argc, char **argv);

void	create_node_back(t_stack **stack, int n);
void	free_stack(t_stack **stack);
t_stack	*create_stack();
t_stack	*init_stack(char **argv, int isLongString);

/* -- Instructions -- */
void	swap(t_stack **stack, char *s_name);
void	push(t_stack **from, t_stack **to, char *to_name);
void	rotate(t_stack **stack, char *name);
void	rotate_reverse(t_stack **stack, char *name);
void	rrotate(t_stack **a, t_stack **b);
void	rrotate_reverse(t_stack **a, t_stack **b);
void	sswap(t_stack **a, t_stack **b);

/* -- A ENLEVER -- */
void print_stack(t_stack *stack, char *name);

#endif