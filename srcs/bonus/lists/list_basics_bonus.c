/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_basics_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 07:56:44 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/21 07:56:46 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 * Function: dlst_new
 * ------------------
 * Description:
 *   Allocates and initializes a new node for a doubly-linked list. The
 *   node is populated with the given value, index, and name, while its
 *   median flag is set to 0 and all pointer fields are initialized to NULL.
 *
 * Parameters:
 *   - int value: The integer value to store in the node.
 *   - int index: The index to assign to the node.
 *   - char name: A character identifier for the node (e.g., 'a').
 *
 * Behavior:
 *   Uses ft_calloc to allocate memory for one node. On success, sets the
 *   node's fields accordingly; otherwise, returns NULL.
 *
 * Returns:
 *   A pointer to the newly created node, or NULL if allocation fails.
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
 *   Appends a new node to the end of a doubly-linked list.
 *
 * Parameters:
 *   - t_dlist **dlist: Pointer to the head pointer of the list.
 *   - t_dlist *new: The new node to be added.
 *
 * Behavior:
 *   If the list is empty, sets the head pointer to the new node.
 *   Otherwise, traverses the list until the last node is found, then links
 *   the new node after it and updates the new node's prev pointer.
 *
 * Returns:
 *   void.
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
 *   Traverses the list from the head node, incrementing a counter for each
 *   node encountered.
 *
 * Returns:
 *   The total number of nodes in the list.
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
 *   Converts an array of integers into a doubly-linked list (stack A).
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head pointer of the resulting list.
 *   - int *tab: The array of integers to convert.
 *   - int len: The number of elements in the array.
 *
 * Behavior:
 *   Creates the first node using the first array element, then iterates
 *   through the remaining elements, creating a new node for each and
 *   appending it to the list using dlst_add_last.
 *
 * Returns:
 *   void.
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
 *   Frees all nodes in a doubly-linked list, releasing the memory allocated
 *   for each node.
 *
 * Parameters:
 *   - t_dlist *head: Pointer to the head of the list.
 *
 * Behavior:
 *   Iterates through the list, saving the next node before freeing the current
 *   node, until the entire list is freed.
 *
 * Returns:
 *   void.
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
