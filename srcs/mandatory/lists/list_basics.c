/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_basics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:24:52 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 01:48:54 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: dlst_new
 * ------------------
 * Description:
 *   Allocates and initializes a new node for a doubly-linked list.
 *   The node is set with the provided value, index, and name.
 *
 * Parameters:
 *   - int value: The integer value to store.
 *   - int index: The index for the node.
 *   - char name: A character identifier for the node.
 *
 * Behavior:
 *   1. Allocates memory for one t_dlist node using ft_calloc.
 *   2. If allocation fails, returns NULL.
 *   3. Sets the node's value, index, and name.
 *   4. Initializes median to 0, and target, next, and prev to NULL.
 *
 * Returns:
 *   - Pointer to the newly created node, or NULL on failure.
 */
t_dlist	*dlst_new(int value, int index, char name)
{
	t_dlist	*new;

	new = ft_calloc(1, sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = index;
	new->median = 0;
	new->name = name;
	new->target = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

/*
 * Function: dlst_add_last
 * -----------------------
 * Description:
 *   Appends a new node at the end of a doubly-linked list.
 *
 * Parameters:
 *   - t_dlist **dlist: Pointer to the head pointer of the list.
 *   - t_dlist *new: Pointer to the node to add.
 *
 * Behavior:
 *   1. If dlist or new is NULL, the function returns immediately.
 *   2. If the list is empty, the new node becomes the head.
 *   3. Otherwise, traverses the list to locate the last node.
 *   4. Links the new node after the last node and updates pointers.
 */
void	dlst_add_last(t_dlist **dlist, t_dlist *new)
{
	t_dlist	*tmp;

	if (!dlist || !new)
		return ;
	if (!*dlist)
	{
		*dlist = new;
		return ;
	}
	tmp = *dlist;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
}

/*
 * Function: dlst_size
 * -------------------
 * Description:
 *   Calculates the number of nodes in a doubly-linked list.
 *
 * Parameters:
 *   - t_dlist **stack: Pointer to the head pointer of the list.
 *
 * Behavior:
 *   1. Traverses the list and counts the nodes.
 *
 * Returns:
 *   - The number of nodes in the list.
 */
int	dlst_size(t_dlist **stack)
{
	int		len;
	t_dlist	*tmp;

	len = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

/*
 * Function: tab_to_list
 * ---------------------
 * Description:
 *   Converts an array of integers into a doubly-linked list.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of the list.
 *   - int *tab: Array of integers to convert.
 *   - int len: Number of elements in the array.
 *
 * Behavior:
 *   1. If the input array is NULL, returns immediately.
 *   2. Creates the first node from tab[0] and assigns it to stack_a.
 *   3. Iterates through the remaining elements in the array.
 *   4. Creates a new node for each element and appends it using
 *      dlst_add_last().
 */
void	tab_to_list(t_dlist **stack_a, int *tab, int len)
{
	int		i;
	t_dlist	*new;

	if (!tab)
		return ;
	*stack_a = dlst_new(tab[0], 0, 'a');
	if (!(*stack_a))
		return ;
	i = 0;
	while (++i < len)
	{
		new = dlst_new(tab[i], i, 'a');
		if (!new)
			return ;
		dlst_add_last(stack_a, new);
	}
}

/*
 * Function: free_list
 * -------------------
 * Description:
 *   Frees all nodes in a doubly-linked list and releases allocated memory.
 *
 * Parameters:
 *   - t_dlist *head: Pointer to the head of the list.
 *
 * Behavior:
 *   1. Iterates through the list.
 *   2. Frees each node and advances to the next node.
 */
void	free_list(t_dlist *head)
{
	t_dlist	*tmp;
	t_dlist	*next;

	tmp = head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}
