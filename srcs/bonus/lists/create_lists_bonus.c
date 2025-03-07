/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:52:46 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 06:28:09 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 * Function: init_stack_a
 * ------------------------
 * Description:
 *   Converts an integer array into a doubly-linked list (stack A).
 *
 * Parameters:
 *   - int *tab: The input integer array.
 *   - int len: The number of elements in the array.
 *
 * Behavior:
 *   Uses tab_to_list to convert the array into a linked list.
 *
 * Returns:
 *   A pointer to the head of the linked list (stack A).
 */
static t_dlist	*init_stack_a(int *tab, int len)
{
	t_dlist	*stack_a;

	tab_to_list(&stack_a, tab, len);
	return (stack_a);
}

/*
 * Function: set_median
 * ---------------------
 * Description:
 *   Identifies and marks the median element in stack A by setting its median
 *   flag to 1. The median is determined from a sorted array of integers.
 *
 * Parameters:
 *   - int *sort: A sorted array of integers.
 *   - int len: The number of elements in the sorted array.
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *
 * Behavior:
 *   1. Validates inputs; if stack_a or sort is NULL or len is less than 2,
 *		does nothing.
 *   2. Computes the median index as len/2.
 *   3. Traverses stack A until finding the node whose value matches the median
 *      value from the sorted array.
 *   4. Sets the median field of that node to 1.
 *
 * Returns:
 *   void.
 */
static void	set_median(int *sort, int len, t_dlist **stack_a)
{
	int		i;
	t_dlist	*tmp;

	if (!stack_a || !sort || len < 2)
		return ;
	i = -1;
	while (++i != (len / 2))
		;
	tmp = *stack_a;
	while (tmp->value != sort[i])
		tmp = tmp->next;
	tmp->median = 1;
}

/*
 * Function: create_lists
 * -----------------------
 * Description:
 *   Initializes the two stacks for the bonus checker by converting an
 *   integer array into a linked list (stack A) and setting up position and
 *   median properties.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *   - int *tab: The input integer array.
 *   - int len: The number of elements in the array.
 *
 * Behavior:
 *   1. Calls init_stack_a to convert the array into a linked list; if the list
 *		is already sorted, init_stack_a frees resources and returns NULL.
 *   2. If stack A is NULL, frees stack B and returns an error code.
 *   3. Allocates a temporary array 'sort' to store a copy of the integers.
 *   4. Uses sort_tab to copy and sort the integer array into 'sort'.
 *   5. Calls set_final_position to assign a final position index to each node in
 *      stack A based on the sorted order.
 *   6. Calls set_median to mark the median element in stack A.
 *   7. Frees the temporary sorted array and returns 0 to indicate success.
 *
 * Returns:
 *   0 if the lists are created successfully, or 1 if an error occurs.
 */
int	create_lists(t_dlist **stack_a, t_dlist **stack_b, int *tab, int len)
{
	int		*sort;

	*stack_a = init_stack_a(tab, len);
	if (!(*stack_a))
		return (free_list(*stack_b), 1);
	sort = ft_calloc(len, sizeof(int));
	if (!sort)
		return (free_list(*stack_a), 1);
	sort_tab(tab, sort, len);
	if (!sort)
		return (free(stack_a), 1);
	set_final_position(sort, len, stack_a);
	set_median(sort, len, stack_a);
	return (free(sort), 0);
}
