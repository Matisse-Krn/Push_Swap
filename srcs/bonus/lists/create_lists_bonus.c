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

static t_dlist	*init_stack_a(int *tab, int len)
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
	return (stack_a);
}

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
