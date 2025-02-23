/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 05:14:33 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 05:54:54 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_a_bonus(t_dlist **stack_a)
{
	t_dlist	*init_last;
	t_dlist	*last;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	last = *stack_a;
	init_last = *stack_a;
	while (init_last->next)
		init_last = init_last->next;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	last->prev = init_last;
	last->next = NULL;
	init_last->next = last;
	reassign_index(stack_a, NULL);
}

void	rotate_b_bonus(t_dlist **stack_b)
{
	t_dlist	*init_last;
	t_dlist	*last;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	last = *stack_b;
	init_last = *stack_b;
	while (init_last->next)
		init_last = init_last->next;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	last->prev = init_last;
	last->next = NULL;
	init_last->next = last;
	reassign_index(NULL, stack_b);
}

void	rotate_r_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	rotate_a_bonus(stack_a);
	rotate_b_bonus(stack_b);
}
