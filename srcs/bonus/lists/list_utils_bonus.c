/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:55:33 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/21 07:55:35 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 * Function: check_if_asc_sorted_list
 * ----------------------------------
 * Description:
 *   Checks whether the given doubly-linked list is sorted in ascending
 *   order.
 *
 * Parameters:
 *   - t_dlist *stack: Pointer to the head of the list.
 *
 * Behavior:
 *   Traverses the list and compares each node's value with the next node's.
 *   If any node has a value greater than its successor, the list is not
 *   sorted in ascending order.
 *
 * Returns:
 *   1 if the list is sorted in ascending order, 0 otherwise.
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
 * Function: reassign_index
 * ------------------------
 * Description:
 *   Recalculates and updates the index field for each node in the provided
 *   stacks. Indices are reassigned sequentially starting at 0.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of stack A.
 *   - t_dlist **stack_b: Pointer to the head pointer of stack B.
 *
 * Behavior:
 *   For each non-NULL stack, traverses the list and sets each node's index
 *   to its position in the list (starting from 0).
 *
 * Returns:
 *   void.
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
 *   Creates a sorted copy of an integer array using a simple bubble sort.
 *
 * Parameters:
 *   - int *tab: The original unsorted integer array.
 *   - int *sort: Array where the sorted copy will be stored.
 *   - int len: The number of elements in the arrays.
 *
 * Behavior:
 *   1. Copies each element from 'tab' to 'sort'.
 *   2. Performs a bubble sort on 'sort' in ascending order.
 *   3. Frees the original 'tab' array after sorting.
 *
 * Returns:
 *   void.
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
 *   Assigns a final position to each node in the list based on a sorted
 *   array of values.
 *
 * Parameters:
 *   - int *sort: A sorted array of integers.
 *   - int len: The number of elements in the sorted array.
 *   - t_dlist **stack: Pointer to the head pointer of the list.
 *
 * Behavior:
 *   For each node in the list, finds its position in the sorted array
 *   (by comparing values) and assigns that position to the node's pos field.
 *
 * Returns:
 *   The pointer to the sorted array 'sort'.
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
