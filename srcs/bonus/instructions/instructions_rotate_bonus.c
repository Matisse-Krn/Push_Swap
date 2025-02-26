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

/*
 * Function: rotate_a_bonus
 * ------------------------
 * Description:
 *   Rotates stack A by moving the first node to the end of the list.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *
 * Behavior:
 *   1. If stack A is empty or contains only one node, does nothing.
 *   2. Stores the first node in 'last' and locates the last node in 'init_last'.
 *   3. Updates the head pointer to the second node.
 *   4. Moves the former first node to the end of the list and updates pointers.
 *   5. Calls reassign_index() to update the indices in stack A.
 *
 * Returns:
 *   void.
 */
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

/*
 * Function: rotate_b_bonus
 * ------------------------
 * Description:
 *   Rotates stack B by moving the first node to the end of the list.
 *
 * Parameters:
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   1. If stack B is empty or contains only one node, does nothing.
 *   2. Stores the first node in 'last' and locates the last node in 'init_last'.
 *   3. Updates the head pointer to the second node.
 *   4. Moves the former first node to the end of the list and updates pointers.
 *   5. Calls reassign_index() to update the indices in stack B.
 *
 * Returns:
 *   void.
 */
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

/*
 * Function: rotate_r_bonus
 * ------------------------
 * Description:
 *   Rotates both stack A and stack B simultaneously.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   Calls rotate_a_bonus() for stack A and rotate_b_bonus() for stack B.
 *
 * Returns:
 *   void.
 */
void	rotate_r_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	rotate_a_bonus(stack_a);
	rotate_b_bonus(stack_b);
}
