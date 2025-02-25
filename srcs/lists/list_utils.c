/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 02:29:14 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 11:20:16 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: check_if_asc_sorted_list
 * -----------------------------------
 * Description:
 *   Checks if a doubly-linked list is sorted in ascending order.
 *
 * Parameters:
 *   - t_dlist *stack: Pointer to the head of the list.
 *
 * Behavior:
 *   1. Iterates through the list and compares each node's value with the
 *      next node.
 *   2. If a node has a greater value than its next, returns 0 immediately.
 *   3. Returns 1 if the entire list is in ascending order.
 *
 * Returns:
 *   - 1 if the list is sorted ascending.
 *   - 0 otherwise.
 */
int	check_if_asc_sorted_list(t_dlist *stack)
{
	t_dlist	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
 * Function: check_if_desc_sorted_list
 * ------------------------------------
 * Description:
 *   Checks if a doubly-linked list is sorted in descending order.
 *
 * Parameters:
 *   - t_dlist *stack: Pointer to the head of the list.
 *
 * Behavior:
 *   1. Iterates through the list and compares each node's value with the
 *      next node.
 *   2. If a node has a lower value than its next, returns 0 immediately.
 *   3. Returns 1 if the list is in descending order.
 *
 * Returns:
 *   - 1 if the list is sorted descending.
 *   - 0 otherwise.
 */
int	check_if_desc_sorted_list(t_dlist *stack)
{
	t_dlist	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->value < tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
 * Function: reassign_index
 * -------------------------
 * Description:
 *   Reassigns the index of each node in both stack_a and stack_b.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of the first list.
 *   - t_dlist **stack_b: Pointer to the head pointer of the second list.
 *
 * Behavior:
 *   1. For each list, iterates through the nodes and resets the index to
 *      sequential values starting from 0.
 *   2. If a list pointer is NULL, that list is skipped.
 */
void	reassign_index(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp;
	int		index;

	if (stack_a)
	{
		tmp = *stack_a;
		index = 0;
		while (tmp)
		{
			tmp->index = index++;
			tmp = tmp->next;
		}
	}
	if (stack_b)
	{
		tmp = *stack_b;
		index = 0;
		while (tmp)
		{
			tmp->index = index++;
			tmp = tmp->next;
		}
	}
}

/*
 * Function: sort_tab
 * ------------------
 * Description:
 *   Copies the contents of one integer array into another and sorts it.
 *
 * Parameters:
 *   - int *tab: The original unsorted integer array.
 *   - int *sort: Array where the sorted elements are stored.
 *   - int len: The number of elements in the arrays.
 *
 * Behavior:
 *   1. Copies each element from 'tab' into 'sort'.
 *   2. Sorts the 'sort' array using a bubble sort algorithm.
 *   3. Frees the original 'tab' array.
 */
void	sort_tab(int *tab, int *sort, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	while (++i < len)
		sort[i] = tab[i];
	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - 1 - i)
		{
			if (sort[j] > sort[j + 1])
			{
				tmp = sort[j];
				sort[j] = sort[j + 1];
				sort[j + 1] = tmp;
			}
		}
	}
	free(tab);
}

/*
 * Function: set_final_position
 * ----------------------------
 * Description:
 *   Assigns the final position to each node in the list based on a sorted
 *   array.
 *
 * Parameters:
 *   - int *sort: Sorted array of integers.
 *   - int len: The number of elements in the sorted array.
 *   - t_dlist **stack: Pointer to the head pointer of the list.
 *
 * Behavior:
 *   1. For each node in the list, finds the corresponding index in the
 *      sorted array.
 *   2. Sets the node's 'pos' field to this index.
 *   3. Returns the sorted array.
 *
 * Returns:
 *   - The pointer to the sorted array.
 */
int	*set_final_position(int *sort, int len, t_dlist **stack)
{
	int		i;
	t_dlist	*tmp;

	tmp = *stack;
	while (tmp)
	{
		i = -1;
		while (tmp->value != sort[++i] && i < len - 1)
			;
		tmp->pos = i;
		tmp = tmp->next;
	}
	return (sort);
}
