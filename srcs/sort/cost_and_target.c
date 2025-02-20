/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_and_target.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:42:59 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 19:49:55 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_final_cost(t_dlist **stack_b)
{
	t_dlist	*tmp;

	tmp = *stack_b;
	while (tmp)
	{
		tmp->cost += tmp->target->cost;
		tmp = tmp->next;
	}
}

/*
 * - Pour chaque element des deux stacks :
 * - Si l'index de l'element actuel indique que l'element se trouve dans la
 * "premiere moitie" de la liste, alors on considere que :
 *		- Son cout = son index :
 *			Le nombre de fois ou il faudra 'rotate_()') la stack vers le haut
 *			pour qu'il revienne en tete de liste);
 * 
 * - Sinon (si il est dans la deuxieme moitie de la liste), on considere que :
 *		- Son cout = [la taille totale de sa stack] - [son index] :
 *			Le nombre de fois ou il faudra 'reverse_rotate_()' la stack vers
 *			le bas pour qu'il revienne en tete de liste);
*/
void	set_cost_to_top(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*tmp;
	int		len_a;
	int		len_b;

	len_a = dlst_size(stack_a);
	len_b = dlst_size(stack_b);
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index <= (len_b / 2))
			tmp->cost = tmp->index;
		else if (tmp->index > (len_b / 2))
			tmp->cost = (len_b - tmp->index);
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->index <= (len_a / 2))
			tmp->cost = tmp->index;
		else if (tmp->index > (len_a / 2))
			tmp->cost = (len_a - tmp->index);
		tmp = tmp->next;
	}
	set_final_cost(stack_b);
}

static t_dlist	*find_minimum_target(t_dlist **stack_a)
{
	t_dlist	*tmp;
	int		min;

	tmp = *stack_a;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	tmp = *stack_a;
	while (tmp->value != min)
		tmp = tmp->next;
	return (tmp);
}

void	set_target(t_dlist **stack_a, t_dlist **stack_b)
{
	t_dlist	*to_move;
	t_dlist	*in_a;
	long	nearest_value;

	to_move = *stack_b;
	while (to_move)
	{
		in_a = *stack_a;
		nearest_value = LONG_MAX;
		while (in_a)
		{
			if (in_a->value > to_move->value && nearest_value > in_a->value)
			{
				to_move->target = in_a;
				nearest_value = in_a->value;
			}
			in_a = in_a->next;
		}
		if (nearest_value == LONG_MAX)
			to_move->target = find_minimum_target(stack_a);
		to_move = to_move->next;
	}
}
