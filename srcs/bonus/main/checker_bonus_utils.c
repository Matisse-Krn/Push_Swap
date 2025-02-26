/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 05:22:11 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 06:29:35 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 * Function: exec_all_two
 * ------------------------
 * Description:
 *   Executes bonus rotate instructions that are not handled by exec_all().
 *   It compares the instruction at tab[i] against the valid bonus rotate
 *   operations.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to stack A.
 *   - t_dlist **stack_b: Pointer to stack B.
 *   - char **tab: Array of instruction strings.
 *   - int i: Index of the current instruction in tab.
 *
 * Behavior:
 *   If tab[i] equals "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", or 
 *   "rrr\n", calls the corresponding bonus rotate function.
 *
 * Returns:
 *   void.
 */
static void	exec_all_two(t_dlist **stack_a,
						t_dlist **stack_b,
						char **tab, int i)
{
	if (!ft_strcmp(tab[i], "ra\n"))
		rotate_a_bonus(stack_a);
	else if (!ft_strcmp(tab[i], "rb\n"))
		rotate_b_bonus(stack_b);
	else if (!ft_strcmp(tab[i], "rr\n"))
		rotate_r_bonus(stack_a, stack_b);
	else if (!ft_strcmp(tab[i], "rra\n"))
		reverse_rotate_a_bonus(stack_a);
	else if (!ft_strcmp(tab[i], "rrb\n"))
		reverse_rotate_b_bonus(stack_b);
	else if (!ft_strcmp(tab[i], "rrr\n"))
		reverse_rotate_r_bonus(stack_a, stack_b);
}

/*
 * Function: exec_all
 * ------------------
 * Description:
 *   Executes all bonus instructions from the provided instruction array.
 *   It selects the appropriate bonus operation based on each instruction.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to stack A.
 *   - t_dlist **stack_b: Pointer to stack B.
 *   - char **tab: Array of instruction strings.
 *
 * Behavior:
 *   Iterates over the instruction array and for each instruction:
 *     - If it matches "pa\n", "pb\n", "sa\n", "sb\n", or "ss\n", calls the
 *       corresponding bonus push or swap function.
 *     - Otherwise, calls exec_all_two() to handle rotate commands.
 *
 * Returns:
 *   void.
 */
void	exec_all(t_dlist **stack_a, t_dlist **stack_b, char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], "pa\n"))
			push_a_bonus(stack_a, stack_b);
		else if (!ft_strcmp(tab[i], "pb\n"))
			push_b_bonus(stack_a, stack_b);
		else if (!ft_strcmp(tab[i], "sa\n"))
			swap_a_bonus(stack_a);
		else if (!ft_strcmp(tab[i], "sb\n"))
			swap_b_bonus(stack_b);
		else if (!ft_strcmp(tab[i], "ss\n"))
			swap_s_bonus(stack_a, stack_b);
		else
			exec_all_two(stack_a, stack_b, tab, i);
	}
}
