/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:43:46 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 06:40:27 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_valid_instruction(char *s)
{
	if (!ft_strcmp(s, "sa\n") || !ft_strcmp(s, "sb\n") || !ft_strcmp(s, "ss\n"))
		return (0);
	if (!ft_strcmp(s, "ra\n") || !ft_strcmp(s, "rb\n") || !ft_strcmp(s, "rr\n"))
		return (0);
	if (!ft_strcmp(s, "rra\n") || !ft_strcmp(s, "rrb\n")
		|| !ft_strcmp(s, "rrr\n"))
		return (0);
	if (!ft_strcmp(s, "pa\n") || !ft_strcmp(s, "pb\n"))
		return (0);
	return (1);
}

static char	**update_new_instructions(int i, char *s, char **list)
{
	char	**new;

	new = ft_calloc(i + 2, sizeof(char *));
	if (!new)
		return (NULL);
	new[i + 1] = NULL;
	new[i] = ft_strdup(s);
	if (list)
	{
		while (--i >= 0)
		{
			new[i] = ft_strdup(list[i]);
			if (!new[i])
				return (free_str(new), new = NULL);
		}
		free_str(list);
	}
	return (new);
}

static char	**add_line(char *s, char **list)
{
	int		i;
	char	**new;

	if (!s)
		return (NULL);
	i = 0;
	if (list)
	{
		while (list[i])
			i++;
	}
	new = update_new_instructions(i, s, list);
	if (!new)
		return (NULL);
	return (free(s), new);
}

static void	exec_and_check(t_dlist **stack_a, t_dlist **stack_b, char **tab)
{
	exec_all(stack_a, stack_b, tab);
	if (check_if_asc_sorted_list(*stack_a) == 1 && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	checker_instructions(t_dlist **stack_a, t_dlist **stack_b)
{
	char	*line;
	char	**instructions;

	instructions = NULL;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line)
		{
			if (check_if_valid_instruction(line) != 0)
			{
				ft_putstr_fd("Error\n", 2);
				free(line);
			}
			else
				instructions = add_line(line, instructions);
		}
	}
	exec_and_check(stack_a, stack_b, instructions);
	free_str(instructions);
	return (0);
}
