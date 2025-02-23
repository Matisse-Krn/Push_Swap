/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:54:15 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 06:06:22 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	determine_what_to_print(t_dlist *stack)
{
	t_dlist	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->target)
		{
			if (tmp->cost)
				ft_printf("   [%d] value: %d  (pos: %d)	(target: %d)	\
cost: %d\n", tmp->index, tmp->value, tmp->pos, tmp->target->value, tmp->cost);
			else
				ft_printf("   [%d] value: %d  (pos: %d)	(target: %d)\n", \
					tmp->index, tmp->value, tmp->pos, tmp->target->value);
		}
		else
		{
			if (tmp->cost)
				ft_printf("   [%d] value: %d  (pos: %d)	cost: %d\n", \
					tmp->index, tmp->value, tmp->pos, tmp->cost);
			else
				ft_printf("   [%d] value: %d  (pos: %d)\n",
					tmp->index, tmp->value, tmp->pos);
		}
		tmp = tmp->next;
	}
}

static void	print_stack(t_dlist *stack, char name)
{
	ft_printf("Stack %c:\n", name);
	if (!stack)
	{
		ft_printf("   (empty)\n");
		return ;
	}
	determine_what_to_print(stack);
	ft_printf("\n");
}

void	print_stacks(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_printf("\n-----------------------\n");
	if (stack_a)
		print_stack(*stack_a, 'A');
	if (stack_b)
		print_stack(*stack_b, 'B');
	ft_printf("-----------------------\n\n\n\n\n");
}
