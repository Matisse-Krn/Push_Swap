/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lists.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:21:16 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 11:19:45 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: init_stack_a
 * ------------------------
 * Description:
 *   Creates stack_a from an integer array. Converts the array into a
 *   doubly-linked list using tab_to_list().
 *
 *   If the list is already sorted in ascending order, the function frees
 *   stack_a and the integer array, then returns NULL.
 *
 *   If the list is sorted in descending order, it reverses the list,
 *   frees both stacks and the integer array, and exits the program.
 *
 * Parameters:
 *   - int *tab: The array of integers.
 *   - int len: The number of elements in tab.
 *   - t_dlist *stack_b: A pointer to stack_b used for list reversal.
 *
 * Returns:
 *   - A pointer to stack_a if created successfully.
 *   - NULL if the list is already sorted in ascending order.
 */
static t_dlist	*init_stack_a(int *tab, int len, t_dlist *stack_b)
{
	t_dlist	*stack_a;

	tab_to_list(&stack_a, tab, len);
	if (check_if_asc_sorted_list(stack_a) == 1)
	{
		free_list(stack_a);
		stack_a = NULL;
		free(tab);
		return (NULL);
	}
	else if (check_if_desc_sorted_list(stack_a) == 1)
	{
		reverse_list(&stack_a, &stack_b, len);
		free_list(stack_a);
		free_list(stack_b);
		free(tab);
		exit(0);
	}
	return (stack_a);
}

/*
 * Function: set_median
 * ----------------------
 * Description:
 *   Sets the median flag on the node in stack_a that contains the median
 *   value. The median is derived from the sorted array 'sort'.
 *
 * Parameters:
 *   - int *sort: A sorted array of integers.
 *   - int len: The length of the sorted array.
 *   - t_dlist **stack_a: A pointer to the pointer of the head of the list.
 *
 * Behavior:
 *   1. If stack_a or sort is NULL, or if len is less than 2, the function
 *      does nothing.
 *   2. Determines the median index as (len / 2) from the sorted array.
 *   3. Traverses stack_a until the node with the median value is found.
 *   4. Marks that node by setting its 'median' field to 1.
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
 * ------------------------
 * Description:
 *   Initializes and creates the two main stacks (stack_a and stack_b)
 *   from an array of integers.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack_a.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack_b.
 *   - int *tab: The array of integers.
 *   - int len: The number of elements in tab.
 *
 * Behavior:
 *   1. Calls init_stack_a() to create stack_a.
 *   2. If stack_a is NULL, frees stack_b and returns an error.
 *   3. Allocates a sorted integer array 'sort' and sorts the 'tab' array.
 *   4. Sets the final positions of elements in stack_a using
 *      set_final_position().
 *   5. Marks the median element in stack_a with set_median().
 *   6. Frees the sorted array and returns 0 on success.
 *
 * Returns:
 *   - 0 if the lists are created successfully.
 *   - 1 if an error occurs during list creation.
 */
int	create_lists(t_dlist **stack_a, t_dlist **stack_b, int *tab, int len)
{
	int		*sort;

	*stack_a = init_stack_a(tab, len, *stack_b);
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
