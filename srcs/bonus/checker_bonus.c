/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:43:46 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/21 05:31:08 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**add_line(char *s, char **list)
{
	int		i;
	char	**new;

	if (!s)
		return (NULL);
	i = -1;
	while (list[++i])
		;
	new = ft_calloc(i + 1, sizeof(char *));
	if (!new)
		return (NULL);
	new[i + 1] = "\0";
	new[i] = s;
	while (--i >= 0)
		new[i] = list[i];
	free (s);
	free_str(list);
	return (new);
}

int	checker_instructions(t_dlist **stack_a,
						t_dlist **stack_b,
						int len/*,
						int *tab*/)
{
	char	*line;
	char	**instructions;
	int		i;

	instructions = NULL;
	line = "";
	i = 0;
	while (line != NULL)
	{
		line = get_next_line(0);
		if (line)
		{
			i++;
			instructions = add_line(line, instructions); // TODO
		}
	}
}
