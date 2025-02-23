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
 * Return 1 if the list is sorted in ascending order, else return 0
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
 * Return 1 if the list is sorted in descending order, else return 0
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
