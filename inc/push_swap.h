/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:48:42 by arocca            #+#    #+#             */
/*   Updated: 2025/01/30 17:22:50 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

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
int		pass_next_nb(char *s, int passed);
int		print(char *s);

/* -- Sources -- */
int	check_no_char(char *s);
int	parse_input_string(char *s);
int	parse_input_args(char **s);
int	check_input(int argc, char **argv);

/* -- Instructions -- */

#endif