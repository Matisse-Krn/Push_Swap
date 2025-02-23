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
