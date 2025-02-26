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

/*
 * Function: swap_a_bonus
 * ----------------------
 * Description:
 *   Swaps the first two elements of stack A by exchanging their value,
 *   position, and median fields.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *
 * Behavior:
 *   1. If stack A has fewer than two elements, does nothing.
 *   2. Swaps the value fields of the first two nodes.
 *   3. Swaps the pos fields of the first two nodes.
 *   4. Swaps the median fields of the first two nodes.
 *   5. Calls reassign_index() to update indices in stack A.
 *
 * Returns:
 *   void.
 */
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

/*
 * Function: swap_b_bonus
 * ----------------------
 * Description:
 *   Swaps the first two elements of stack B by exchanging their value,
 *   position, and median fields.
 *
 * Parameters:
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   1. If stack B has fewer than two elements, does nothing.
 *   2. Swaps the value fields of the first two nodes.
 *   3. Swaps the pos fields of the first two nodes.
 *   4. Swaps the median fields of the first two nodes.
 *   5. Calls reassign_index() to update indices in stack B.
 *
 * Returns:
 *   void.
 */
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

/*
 * Function: swap_s_bonus
 * ----------------------
 * Description:
 *   Simultaneously swaps the first two elements of both stack A and stack B.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   Calls swap_a_bonus() on stack A and swap_b_bonus() on stack B.
 *
 * Returns:
 *   void.
 */
void	swap_s_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	swap_a_bonus(stack_a);
	swap_b_bonus(stack_b);
}
