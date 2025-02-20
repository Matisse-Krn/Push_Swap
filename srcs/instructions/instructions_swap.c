/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 07:38:52 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/16 10:09:53 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_dlist **stack_a, char name)
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
	if (name == 'a')
		ft_printf("sa\n");
	reassign_index(stack_a, NULL);
}

void	swap_b(t_dlist **stack_b, char name)
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
	if (name == 'b')
		ft_printf("sb\n");
	reassign_index(NULL, stack_b);
}

void	swap_s(t_dlist **stack_a, t_dlist **stack_b, char name)
{
	if (name == 's')
	{
		swap_a(stack_a, name);
		swap_b(stack_b, name);
		ft_printf("ss\n");
	}
}
