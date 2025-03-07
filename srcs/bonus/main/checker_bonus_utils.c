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
 *   1. If tab[i] matches a valid rotation or reverse rotation instruction,
 *      calls the corresponding function.
 *   2. If the instruction is unrecognized, prints "Error" and returns 1.
 *
 * Returns:
 *   - 1 on Error
 *   - 0 on success
 */
static int	exec_all_two(t_dlist **stack_a,
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
	else
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}

/*
 * Function: exec_all
 * ------------------
 * Description:
 *   Executes all instructions in the given list on the provided stacks.
 *   If an invalid instruction is encountered, execution stops and an
 *   error is returned.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to stack A.
 *   - t_dlist **stack_b: Pointer to stack B.
 *   - char **tab: Array of instruction strings.
 *
 * Behavior:
 *   1. Iterates over the instruction list.
 *   2. Executes each instruction using the corresponding function.
 *   3. If the instruction is not recognized, calls exec_all_two(),
 *      which prints "Error" and stops execution.
 *
 * Returns:
 *   - 0 if all instructions were executed successfully.
 *   - 1 if an invalid instruction was encountered.
 */
int	exec_all(t_dlist **stack_a, t_dlist **stack_b, char **tab)
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
		else if (exec_all_two(stack_a, stack_b, tab, i))
			return (1);
	}
	return (0);
}
