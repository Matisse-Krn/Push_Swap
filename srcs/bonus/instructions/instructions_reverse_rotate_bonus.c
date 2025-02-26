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

#include "push_swap_bonus.h"

/*
 * Function: reverse_rotate_a_bonus
 * ---------------------------------
 * Description:
 *   Performs a reverse rotation on stack A by moving the last element
 *   to the front of the list.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *
 * Behavior:
 *   1. If stack A is empty or has only one element, does nothing.
 *   2. Traverses stack A to locate the last node.
 *   3. Detaches the last node from its previous position.
 *   4. Moves the detached node to the front and updates the head pointer.
 *   5. Updates necessary pointers to maintain list integrity.
 *   6. Reassigns indices for stack A.
 *
 * Returns:
 *   void.
 */
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

/*
 * Function: reverse_rotate_b_bonus
 * ---------------------------------
 * Description:
 *   Performs a reverse rotation on stack B by moving the last element
 *   to the front of the list.
 *
 * Parameters:
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   1. If stack B is empty or has only one element, does nothing.
 *   2. Traverses stack B to locate the last node.
 *   3. Detaches the last node from its previous position.
 *   4. Moves the detached node to the front and updates the head pointer.
 *   5. Updates necessary pointers to maintain list integrity.
 *   6. Reassigns indices for stack B.
 *
 * Returns:
 *   void.
 */
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

/*
 * Function: reverse_rotate_r_bonus
 * ---------------------------------
 * Description:
 *   Simultaneously performs a reverse rotation on both stack A and stack B.
 *   The last element of each stack is moved to the front.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   Calls reverse_rotate_a_bonus() on stack A and reverse_rotate_b_bonus()
 *   on stack B.
 *
 * Returns:
 *   void.
 */
void	reverse_rotate_r_bonus(t_dlist **stack_a, t_dlist **stack_b)
{
	reverse_rotate_a_bonus(stack_a);
	reverse_rotate_b_bonus(stack_b);
}
