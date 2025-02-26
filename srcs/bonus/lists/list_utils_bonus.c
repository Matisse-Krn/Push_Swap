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
