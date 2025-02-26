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

#include "push_swap_bonus.h"

/*
 * Function: check_if_valid_instruction
 * --------------------------------------
 * Description:
 *   Checks if the given instruction string 's' matches one of the valid
 *   operations.
 *
 * Parameters:
 *   - char *s: The instruction string to validate.
 *
 * Behavior:
 *   Compares 's' against each valid instruction using ft_strcmp.
 *   Returns 0 if a match is found, 1 otherwise.
 *
 * Returns:
 *   - 0 if 's' is valid.
 *   - 1 if 's' is not a valid instruction.
 */
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

/*
 * Function: update_new_instructions
 * ---------------------------------
 * Description:
 *   Creates a new array of instruction strings by appending the new
 *   instruction 's' to the existing list.
 *
 * Parameters:
 *   - int i: The current number of instructions in the list.
 *   - char *s: The new instruction string to add.
 *   - char **list: The existing array of instruction strings.
 *
 * Behavior:
 *   1. Allocates an array with (i + 2) slots (including NULL terminator).
 *   2. Duplicates the new instruction 's' into slot i.
 *   3. If 'list' exists, duplicates each string from 'list' into the new
 *      array in reverse order.
 *   4. Frees the old 'list' using free_str.
 *
 * Returns:
 *   - A new NULL-terminated array of instruction strings on success.
 *   - NULL on memory allocation failure.
 */
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

/*
 * Function: add_line
 * ------------------
 * Description:
 *   Adds a new instruction line 's' to the current array of instructions.
 *
 * Parameters:
 *   - char *s: The new instruction string to add.
 *   - char **list: The existing array of instruction strings.
 *
 * Behavior:
 *   1. If 's' is NULL, returns NULL.
 *   2. Counts the number of strings in 'list'.
 *   3. Calls update_new_instructions() to create the updated array.
 *   4. Frees the original 's' after it has been added.
 *
 * Returns:
 *   - The updated array of instruction strings, or NULL on error.
 */
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

/*
 * Function: exec_and_check
 * ------------------------
 * Description:
 *   Executes all the instructions in the provided array on the two stacks,
 *   then verifies the final state.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to stack A.
 *   - t_dlist **stack_b: Pointer to stack B.
 *   - char **tab: Array of instruction strings to execute.
 *
 * Behavior:
 *   Calls exec_all() to perform the operations, then checks whether stack A
 *   is sorted in ascending order and stack B is empty. Prints "OK" if both
 *   conditions are met; otherwise, prints "KO".
 *
 * Returns:
 *   void.
 */
static void	exec_and_check(t_dlist **stack_a, t_dlist **stack_b, char **tab)
{
	exec_all(stack_a, stack_b, tab);
	if (check_if_asc_sorted_list(*stack_a) == 1 && !(*stack_b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

/*
 * Function: checker_instructions
 * ------------------------------
 * Description:
 *   Reads instructions from standard input, validates each one, and builds
 *   an array of valid instructions. Once input is complete, executes the
 *   instructions on the provided stacks and prints the result.
 *
 * Parameters:
 *   - t_dlist **stack_a: Pointer to stack A.
 *   - t_dlist **stack_b: Pointer to stack B.
 *
 * Behavior:
 *   Continuously reads lines using get_next_line() until EOF is reached.
 *   For each line, if the instruction is invalid, prints "Error" to stderr
 *   and frees the line; otherwise, adds it to the instructions list via
 *   add_line(). After input, if any instructions were collected, calls
 *   exec_and_check() to execute them and frees the instructions array.
 *
 * Returns:
 *   0.
 */
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
	if (instructions)
	{
		exec_and_check(stack_a, stack_b, instructions);
		free_str(instructions);
	}
	return (0);
}
