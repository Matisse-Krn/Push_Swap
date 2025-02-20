/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:46:50 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/17 21:20:16 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_list(t_dlist **stack_a, t_dlist **stack_b, int len)
{
	int	i;

	if (len == 2)
		swap_a(stack_a, 'a');
	else if (len == 3)
	{
		swap_a(stack_a, 'a');
		reverse_rotate_a(stack_a, 'a');
	}
	else
	{
		i = -1;
		while (++i < len - 1)
			push_b(stack_a, stack_b);
		while (i-- > 0)
		{
			reverse_rotate_b(stack_b, 'b');
			push_a(stack_a, stack_b);
		}
		reverse_rotate_a(stack_a, 'a');
	}
}
