/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 14:07:13 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/19 11:17:08 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	- Principles:
		- From 'sort_stack()', all elements of 'stack_a' except the last 3
		  are sent to 'stack_b' ('pb');
		  
		- From 'sort_stack()', using 'sort_three()', the last 3 elements of
		  'stack_a' are sorted;
		  
		- As soon as an element is sent to 'stack_b' (after a 'push_b()'),
		  we check if its value is greater than the median value of the 
		  sorted list:
		  if it is greater, we "send" it to the bottom (end) of 'stack_b'
		  using 'rotate_b()' ('rb');
		  
		- From 'sort_stack()', once all elements initially in
		  'stack_a' except 3 are sent to 'stack_b', we calculate at each
		  step the movement cost for each element in 'stack_b', so that the
		  given element is placed in the best position: above its
		  'target'.
		   	- By best position, we mean in 'set_target()':
		   		- Just "above" its 'target': an element in 'stack_a' whose
		   		  value is greater than its own and the closest to its
		   		  value.
		   		- If no element in 'stack_a' is greater than it, then
		   		  it should go "above" the element with the smallest
		   		  value among all elements in 'stack_a' (identified using
		   		  'find_minimum_target()').
		   	- The cost is calculated as follows using 'set_cost_to_top()'
			  and 'set_final_cost()':
		   		- To determine "how much it would cost", we check:
		   			- For each element in both stacks:
		   			- If the index of the current element indicates that it
		   			  is in the "first half" of the list, then we consider:
						- Its cost = its index:
						  The number of times we need to 'rotate_()'
						  the stack upwards for it to return
						  to the top of the list;
					- Otherwise (if it is in the second half of the
					  list), we consider:
						- Its cost = [total stack size] - [its index]:
			    			  The number of times we need to
			    			  'reverse_rotate_()' the stack downwards
			    			  for it to return to the top of the list);
			   		- Using 'set_cost_to_top()', we check in 'stack_b'
			   		  how much it would cost (in number of instructions) to
			   		  "bring" the current element (the one for which we
					  calculate the cost) to the top of 'stack_b';
			   		- Using 'set_cost_to_top()', we check in 'stack_a'
			   		  how much it would cost (in number of instructions) to
			   		  "bring" the 'target' of the element in 'stack_b' to the
					  top of 'stack_a';
			   		- Using 'set_final_cost()', we sum the two
			   		  obtained results (number of instructions) to get
			   		  the total cost of placing the element at the "ideal"
					  location;

		- From 'sort_stacks()', we call 'determine_next_movement()' to
		  retrieve the element that is the cheapest to correctly place in
		  'stack_a'. If multiple elements in 'stack_b' have the same
		  cost in terms of instructions, the first encountered element is
		  selected;
  
		- From 'determine_next_movement()', we retrieve using
		  'move_to_top()' the actions to perform to bring to the top,
		  with the least instructions possible, the two elements of the
		  pair [cheapest element in 'stack_b'] and 
		  [its 'target' in 'stack_a']:
		  	- '-1' = 'reverse_rotate_()';
		  	- '1' = 'rotate_()';
		  	- '0' = nothing to do, already at the top of the list;
			- If the results for the element in 'stack_b' and its target in
			  'stack_a' are identical, then we "merge" them to reduce the
			  number of instructions:
				- Example: if 'rotate_a()' ('1') and 'rotate_b()' ('1')
				  are returned, then we will perform 'rotate_r()');

				- We 'push_a()' the element from 'stack_b' as soon as it and its
				  target are at the top of their respective stacks;
			
		- Finally, once all elements from 'stack_b' are sent to
		  'stack_a', we call from 'sort_stacks()' the function
		  'finish_sort()', which is used to perform the required number of
		  'reverse_rotate_a()' or 'rotate_a()' needed to align the sorted
		  start with the rest of 'stack_a'.
		  Checking whether the end of "the step" (= sorted head of the list
		  but not aligned with the rest) is before or after the midpoint of
		  'stack_a' to decide whether to 'rotate_a()' or 
		  'reverse_rotate_a()' optimized the algorithm by nearly 1000
		  instructions in a series of 500 elements! 
			
			
	- Performance v0 (WITHOUT 'finish_sort()' optimization), across 10,000
	  test series:
		- For 500 numbers:
			- median at 5608 instructions;
			- worst case at 6215 instructions;
			- best case at 5048 instructions;

		- For 100 numbers:
			- median at 634 instructions;
			- worst case at 743 instructions;
			- best case at 527 instructions;

		- For 5 numbers:
			- median at 10 instructions;
			- worst case at 13 instructions;
			- best case at 0 instruction;

		- For 3 numbers:
			- median at 2 instructions;
			- worst case at 3 instructions;
			- best case at 0 instruction;		
	
	
	- Performance v1 (WITH 'finish_sort()' optimization):
		- For 500 numbers (out of 10,000 series):
			- median at 4783 instructions;
			- worst case at 5260 instructions;
			- best case at 4278 instructions;

		- For 100 numbers (out of 500,000 series):
			- median at 594 instructions;
			- worst case at 700 instructions;
			- best case at 485 instructions;

		- For 5 numbers (out of 100,000 series):
			- median at 9 instructions;
			- worst case at 12 instructions;
			- best case at 0 instruction;

		- For 3 numbers (out of 100,000 series):
			- median at 1 instruction;
			- worst case at 2 instructions;
			- best case at 0 instruction;
*/

/*
 * Function: free_str
 * ------------------
 * Description:
 *   Frees a NULL-terminated array of strings. This function iterates over
 *   each string in the given array, frees each individual string, and then
 *   frees the array pointer itself.
 *
 * Parameters:
 *   - char **tabtab: A pointer to a NULL-terminated array of strings.
 *
 * Behavior:
 *   - If the input pointer is NULL, the function does nothing.
 *   - Otherwise, it loops through each element until it encounters a NULL
 *     pointer, freeing each string.
 *   - Finally, it frees the pointer to the array itself.
 *
 * Returns:
 *   - void. (The function does not return any value.)
 */
void	free_str(char **tabtab)
{
	int	i;

	if (!tabtab)
		return ;
	i = -1;
	while (tabtab[++i])
	{
		free(tabtab[i]);
		tabtab[i] = NULL;
	}
	free(tabtab);
	tabtab = NULL;
}

static char	**take_all_args(int argc, char **argv)
{
	char	**input;
	int		i;

	input = ft_calloc(argc, sizeof(char *));
	if (!input)
		return (NULL);
	i = -1;
	while (++i < argc - 1)
	{
		if (!argv[i + 1] || !(*argv[i + 1]))
			return (free_str(input), input = NULL);
		input[i] = ft_strdup(argv[i + 1]);
		if (!input[i])
			return (NULL);
	}
	input[i] = NULL;
	return (input);
}

/*
 * Function: extract_input
 * -------------------------
 * Description:
 *   Extracts the input numbers from the command-line arguments.
 *   Supports two formats:
 *     1. A single string containing all numbers separated by spaces
 *        (e.g., "./push_swap '54 32 87'").
 *     2. Multiple arguments provided one by one (e.g., "./push_swap 54 32 87").
 *
 * Parameters:
 *   - int argc: The total number of command-line arguments.
 *   - char **argv: The array of command-line arguments.
 *
 * Behavior:
 *   - If exactly one argument (besides the program name) is provided, the
 *     function uses ft_split to break
 *     the string into an array of substrings using spaces as delimiters.
 *   - If more than one argument is provided, it calls take_all_args to duplicate
 *     each argument into a new array.
 *   - Performs basic error checking to ensure that the input is valid.
 *
 * Returns:
 *   - A pointer to a newly allocated, NULL-terminated array of strings
 *     representing the extracted input.
 *   - Returns NULL if no valid input is provided or if an error occurs
 *     during extraction.
 */
static char	**extract_input(int argc, char **argv)
{
	char	**input;

	if (argc == 2)
	{
		if (!argv[1])
			return (NULL);
		input = ft_split(argv[1], ' ');
		if (!input)
			return (NULL);
	}
	else if (argc > 2)
	{
		input = take_all_args(argc, argv);
		if (!input)
			return (NULL);
	}
	else
		return (NULL);
	return (input);
}

/*
 * Function: main
 * --------------
 * Description:
 *   Entry point of the push_swap program. It handles input extraction, parsing,
 *   conversion, list creation, sorting, and memory cleanup.
 *
 * Parameters:
 *   - int argc: The total number of command-line arguments.
 *   - char **argv: The array of command-line arguments.
 *
 * Behavior:
 *   1. Initializes two linked list pointers (stack_a and stack_b) to represent
 *      the stacks.
 *   2. Calls extract_input() to process command-line arguments into a usable
 *		array of strings.
 *		If extraction fails, the program exits with an error code.
 *   3. Performs input validation by calling parsing_check() on the extracted
 *		input.
 *		If the check fails, it frees the input and exits with an error.
 *   4. Converts the input strings into an array of integers using
 *		convert_str_to_tab(), updating the length (len).
 *      If conversion fails, it frees the input and exits with an error.
 *   5. Frees the input strings once they are no longer needed.
 *   6. Creates two linked lists (stack_a and stack_b) using the array of
 *		integers by calling create_lists().
 *      If list creation fails, the program exits with an error.
 *   7. Sorts the stacks by invoking sort_stacks().
 *   8. Cleans up the memory allocated for the stacks using free_list() for
 *		both stack_a and stack_b.
 *   9. Returns 0 to indicate successful execution.
 *
 * Returns:
 *   - int: 0 if the program executes successfully,
 *			or 1 if an error occurs at any step.
 */
int	main(int argc, char **argv)
{
	char	**input;
	int		*tab;
	int		len;
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	len = 0;
	input = extract_input(argc, argv);
	if (!input)
		return (1);
	if (parsing_check(input))
		return (free_str(input), 1);
	tab = convert_str_to_tab(input, &len);
	if (!tab)
		return (free_str(input), 1);
	free_str(input);
	if (create_lists(&stack_a, &stack_b, tab, len))
		return (1);
	sort_stacks(&stack_a, &stack_b, len);
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

/*
 * Cas spécifiques à tester

    Cas valides simples :
        "4 1 2 3" (entrée en une seule chaîne)
        4 1 2 3 (entrée en arguments séparés)
        -42 0 42 2147483647 -2147483648

    Cas limites et bords :
        2147483647 -2147483648 (limites de l'entier 32 bits)
        0 (cas minimaliste)
        1 2 3 4 5 6 7 8 9 10 (test de liste ordonnée)
        10 9 8 7 6 5 4 3 2 1 (test de liste inversée)

    Cas d'erreurs de format :
        42a (nombre invalide contenant une lettre)
        +42- (mauvais placement des signes)
        --5 (plusieurs signes)
        4.2 (nombre non entier)
        "" (entrée vide)
 " " (entrée uniquement constituée d'espaces)
        " 4 5 6 " (espaces excessifs mais valides)

    Cas de dépassement des limites :
        2147483648 (dépassement de INT_MAX)
        -2147483649 (dépassement de INT_MIN)
        9999999999 (nombre trop grand)
        -9999999999 (nombre trop petit)

    Cas de doublons :
        1 2 3 4 5 2 (un nombre en double)
        100 -100 100 (nombre positif et négatif identiques)
        2147483647 2147483647 (duplication du max)
        -2147483648 -2147483648 (duplication du min)

		
    Sorting 3 values: no more than 3 actions.
    
	Sorting 5 values: no more than 12 actions.
    
	Sorting 100 values: rating from 1 to 5 points depending on the number of
	actions:
        5 points for less than 700 actions
        4 points for less than 900
        3 points for less than 1100
        2 points for less than 1300
        1 point for less than 1500
    
	Sorting 500 values: rating from 1 to 5 points depending on the number of
	actions:
        5 points for less than 5500 actions
        4 points for less than 7000
        3 points for less than 8500
        2 points for less than 10000
        1 point for less than 11500

*/
