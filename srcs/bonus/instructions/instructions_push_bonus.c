/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_push_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:26:17 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 05:53:07 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_a_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	if (*stack_b)
		(*stack_b)->prev = NULL;
	tmp->next = *stack_a;
	if (*stack_a)
		(*stack_a)->prev = tmp;
	*stack_a = tmp;
	(*stack_a)->name = 'a';
	reassign_index(stack_a, stack_b);
}

void	push_b_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp;

	if (!stack_a || !(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	if (*stack_a)
		(*stack_a)->prev = NULL;
	if (!(*stack_b))
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->name = 'b';
		*stack_b = tmp;
	}
	else
	{
		tmp->next = *stack_b;
		(*stack_b)->prev = tmp;
		*stack_b = tmp;
		(*stack_b)->name = 'b';
	}
	reassign_index(stack_a, stack_b);
}
