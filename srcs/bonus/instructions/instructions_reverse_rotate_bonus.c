/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_reverse_rotate_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 09:16:11 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 05:55:10 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a_bonus(t_dlist **stack_a)
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
	reassign_index(stack_a, NULL);
}

void	reverse_rotate_b_bonus(t_dlist **stack_b)
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
	reassign_index(NULL, stack_b);
}

void	reverse_rotate_r_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	reverse_rotate_a_bonus(stack_a);
	reverse_rotate_b_bonus(stack_b);
}
