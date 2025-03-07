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

/*
 * Function: reverse_list
 * ------------------------
 * Description:
 *   Reverses or sorts a list using a simple algorithm that varies based
 *   on the number of elements.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to the head of stack A.
 *   - t_dlist **stack_b: Pointer to the head of stack B.
 *   - int len: The number of elements in stack A.
 *
 * Behavior:
 *   1. If there are exactly 2 elements, it swaps the two nodes.
 *
 *   2. If there are exactly 3 elements, it swaps the first two nodes and
 *      then performs a reverse rotation on stack A.
 *
 *   3. For lists with more than 3 elements:
 *      a. It pushes all but one element from stack A to stack B.
 *      b. Then, it reverse rotates stack B and pushes each element back
 *         to stack A.
 *      c. Finally, it performs one more reverse rotation on stack A.
 *
 * Returns:
 *   - void.
 */
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
