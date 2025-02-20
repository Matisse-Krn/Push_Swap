/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:16:11 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/17 20:48:37 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_dlist **stack_a, char name)
{
	t_dlist	*first;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first = *stack_a;
	while (first->next)
		first = first->next;
	first->prev->next = NULL;
	first->next = *stack_a;
	first->prev = NULL;
	*stack_a = first;
	(*stack_a)->next->prev = first;
	if (name == 'a')
		ft_printf("rra\n");
	reassign_index(stack_a, NULL);
}

void	reverse_rotate_b(t_dlist **stack_b, char name)
{
	t_dlist	*first;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first = *stack_b;
	while (first->next)
		first = first->next;
	first->prev->next = NULL;
	first->next = *stack_b;
	first->prev = NULL;
	*stack_b = first;
	(*stack_b)->next->prev = first;
	if (name == 'b')
		ft_printf("rrb\n");
	reassign_index(NULL, stack_b);
}

void	reverse_rotate_r(t_dlist **stack_a, t_dlist **stack_b, char name)
{
	if (name == 'r')
	{
		reverse_rotate_a(stack_a, name);
		reverse_rotate_b(stack_b, name);
		ft_printf("rrr\n");
	}
}
