/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:38:36 by arocca            #+#    #+#             */
/*   Updated: 2025/02/04 18:06:40 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **from, t_stack **to, char *to_name)
{
	t_node	*tmp;

	if (!from || !(*from) || !((*from)->top) || !to || !(*to))
		return ;
	tmp = (*from)->top;
	(*from)->top = tmp->next;
	if ((*from)->top == NULL)
		(*from)->bottom = NULL;
	tmp->next = (*to)->top;
	(*to)->top = tmp;
	if ((*to)->size == 0)
		(*to)->bottom = tmp;
	(*from)->size--;
	(*to)->size++;
	print(to_name);
	return ;
}
