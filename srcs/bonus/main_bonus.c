/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:05:06 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/22 06:21:33 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Free all arrays in the array of arrays, to prevent leaks
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
 * Determines whether elements are passed :
 *	  in a single string : `./push_swap “54 32 87"`
 *	  one by one : `./push_swap 54 32 87`
 * Extract each element and assign it to an array of arrays 'input'
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
			return (free(input), NULL);
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
 * Calls 'extract_input()' to extract the 'input' of all elements,
 * Calls the 'parsing_check()' function to perform all input
 * checks/verifications.
 * Convert the input string into a array of int
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
	checker_instructions(&stack_a, &stack_b);
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
