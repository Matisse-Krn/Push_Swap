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

/*
 * Function: swap_a
 * ----------------
 * Description:
 *   Swaps the first two elements of stack_a by exchanging their value,
 *   position, and median fields.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - char name: Identifier; if 'a', prints the operation "sa".
 *
 * Behavior:
 *   1. If stack_a is empty or has less than two nodes, the function
 *      returns.
 *   2. Swaps the value, pos, and median fields of the first two nodes.
 *   3. If name is 'a', prints "sa".
 *   4. Calls reassign_index to update node indices in stack_a.
 *
 * Returns:
 *   - void.
 */
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
	tmp = (*stack_a)->median;
	(*stack_a)->median = (*stack_a)->next->median;
	(*stack_a)->next->median = tmp;
	if (name == 'a')
		ft_printf("sa\n");
	reassign_index(stack_a, NULL);
}

/*
 * Function: swap_b
 * ----------------
 * Description:
 *   Swaps the first two elements of stack_b by exchanging their value,
 *   position, and median fields.
 *
 * Parameters:
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *   - char name: Identifier; if 'b', prints the operation "sb".
 *
 * Behavior:
 *   1. If stack_b is empty or has less than two nodes, the function
 *      returns.
 *   2. Swaps the value, pos, and median fields of the first two nodes.
 *   3. If name is 'b', prints "sb".
 *   4. Calls reassign_index to update node indices in stack_b.
 *
 * Returns:
 *   - void.
 */
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
	tmp = (*stack_b)->median;
	(*stack_b)->median = (*stack_b)->next->median;
	(*stack_b)->next->median = tmp;
	if (name == 'b')
		ft_printf("sb\n");
	reassign_index(NULL, stack_b);
}

/*
 * Function: swap_s
 * ----------------
 * Description:
 *   Simultaneously swaps the first two elements of both stack_a and
 *   stack_b.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *   - char name: Identifier; if 's', performs both swaps and prints "ss".
 *
 * Behavior:
 *   1. If name equals 's', calls swap_a and swap_b for the two stacks.
 *   2. Prints "ss" to indicate a simultaneous swap operation.
 *
 * Returns:
 *   - void.
 */
void	swap_s(t_dlist **stack_a, t_dlist **stack_b, char name)
{
	if (name == 's')
	{
		swap_a(stack_a, name);
		swap_b(stack_b, name);
		ft_printf("ss\n");
	}
}
