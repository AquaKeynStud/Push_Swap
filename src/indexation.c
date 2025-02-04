/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keyn <keyn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 23:44:01 by keyn              #+#    #+#             */
/*   Updated: 2025/02/04 11:19:13 by keyn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	*create_tab(t_stack **stack)
// {
// 	t_node	*current;
// 	int		*tab;
// 	int		i;

// 	i = 0;
// 	tab = (int *)malloc(sizeof(int) * (*stack) -> size);
// 	if (!tab)
// 		return ;
// 	current = (*stack) -> top;
// 	while (current)
// 	{
// 		tab[i] = current -> value;
// 		current = current -> next;
// 		i++;
// 	}
// 	tab[i] = 0;
// 	return (tab);
// }