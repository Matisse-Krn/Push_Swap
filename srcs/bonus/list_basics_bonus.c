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
