/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:54:15 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 06:06:22 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: determine_what_to_print
 * ---------------------------------
 * Description:
 *   Traverses a doubly-linked list and prints each node's data in a
 *   formatted manner. Depending on whether a node has a target and/or a
 *   cost, it prints additional details.
 *
 * Parameters:
 *   - t_dlist *stack: Pointer to the head of the linked list.
 *
 * Behavior:
 *   1. Iterates through the list node by node.
 *   2. If a node has a non-NULL target pointer:
 *      a. If the cost is non-zero, prints the node's index, value,
 *         position, target's value, and cost.
 *      b. Otherwise, prints the index, value, position, and target's
 *         value.
 *   3. If the target pointer is NULL:
 *      a. If the cost is non-zero, prints the index, value, position,
 *         and cost.
 *      b. Otherwise, prints only the index, value, and position.
 *
 * Note:
 *   - This function uses ft_printf for output and assumes the node
 *     structure contains members: index, value, pos, target, and cost.
 */
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

/*
 * Function: print_stack
 * ---------------------
 * Description:
 *   Prints the contents of a single stack. First, it prints the stack header
 *   using the provided name. If the stack is empty, it prints "(empty)". If not,
 *   it calls determine_what_to_print() to print each node's details, and then
 *   prints a newline.
 *
 * Parameters:
 *   - t_dlist *stack: Pointer to the head of the stack.
 *   - char name: Identifier for the stack (e.g., 'A' or 'B').
 *
 * Returns:
 *   - void.
 */
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

/*
 * Function: print_stacks
 * ----------------------
 * Description:
 *   Prints both stacks, stack_a and stack_b, with formatting. It prints a
 *   decorative separator before and after printing the stacks. For each
 *   non-NULL stack pointer, it calls print_stack() with the appropriate name.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Returns:
 *   - void.
 */
void	print_stacks(t_dlist **stack_a, t_dlist **stack_b)
{
	ft_printf("\n-----------------------\n");
	if (stack_a)
		print_stack(*stack_a, 'A');
	if (stack_b)
		print_stack(*stack_b, 'B');
	ft_printf("-----------------------\n\n\n\n\n");
}
