/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 07:38:52 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 05:55:28 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a_bonus(t_dlist **stack_a)
{
	int	tmp;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	tmp = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = tmp;
	tmp = (*stack_a)->pos;
	(*stack_a)->pos = (*stack_a)->next->pos;
	(*stack_a)->next->pos = tmp;
	tmp = (*stack_a)->median;
	(*stack_a)->median = (*stack_a)->next->median;
	(*stack_a)->next->median = tmp;
	reassign_index(stack_a, NULL);
}

void	swap_b_bonus(t_dlist **stack_b)
{
	int	tmp;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	tmp = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = tmp;
	tmp = (*stack_b)->pos;
	(*stack_b)->pos = (*stack_b)->next->pos;
	(*stack_b)->next->pos = tmp;
	tmp = (*stack_b)->median;
	(*stack_b)->median = (*stack_b)->next->median;
	(*stack_b)->next->median = tmp;
	reassign_index(NULL, stack_b);
}

void	swap_s_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	swap_a_bonus(stack_a);
	swap_b_bonus(stack_b);
}
