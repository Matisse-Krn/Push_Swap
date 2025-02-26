/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:13:18 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/21 04:13:20 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

/*
 * Function: check_if_valid_digit
 * --------------------------------
 * Description:
 *   Checks if a string represents a valid integer format. It verifies that
 *   every character is either a digit or a valid sign ('+' or '-'), and that
 *   the sign is used correctly.
 *
 * Parameters:
 *   - char *s: The input string to be validated.
 *
 * Behavior:
 *   1. Returns -1 if the string is NULL or empty.
 *   2. Iterates through each character in the string.
 *   3. If a character is neither a digit nor a sign, returns 1.
 *   4. Increments a counter when a '+' or '-' is encountered.
 *   5. If a sign is not followed by a digit or if more than one sign is
 *      found, returns 1.
 *   6. Returns 0 if the string is a valid representation.
 *
 * Returns:
 *   - 0 if the string is valid.
 *   - 1 if an invalid character or sign misuse is detected.
 *   - -1 if the string is NULL or empty.
 */
static int	check_if_valid_digit(char *s)
{
	int	i;
	int	sign;

	if (!s || !(*s))
		return (-1);
	i = -1;
	sign = 0;
	while (s[++i])
	{
		if (s[i] != '-' && s[i] != '+' && !(s[i] >= '0' && s[i] <= '9'))
			return (1);
		if (s[i] == '+' || s[i] == '-')
		{
			sign++;
			if (!s[i + 1] || sign > 1)
				return (1);
		}
	}
	return (0);
}

/*
 * Function: check_int_overflow
 * ------------------------------
 * Description:
 *   Validates that the numeric value in the string fits within the integer
 *   range. It converts the string to an integer using ft_atoi, then back to a
 *   string with ft_itoa. The original string is simplified using
 *   delete_surplus and compared to the converted string to detect overflow or
 *   invalid formatting.
 *
 * Parameters:
 *   - char *s: The string representing the integer.
 *
 * Behavior:
 *   1. Converts the string to an integer (atoi_res) using ft_atoi.
 *   2. If atoi_res is 0 and the string does not properly represent zero,
 *      returns -1.
 *   3. Converts the integer back to a string (itoa_res) using ft_itoa.
 *   4. Simplifies the original string using delete_surplus.
 *   5. Compares the simplified string to itoa_res using ft_strcmp.
 *   6. Frees allocated memory before returning.
 *
 * Returns:
 *   - 0 if the string is within the integer range and properly formatted.
 *   - 1 if an overflow or formatting error is detected.
 *   - -1 if the result of ft_atoi is zero but the initial string does not
 *	   represent a zero.
 */
static int	check_int_overflow(char *s)
{
	int		atoi_res;
	char	*itoa_res;
	char	*simple_s;

	atoi_res = ft_atoi(s);
	if (atoi_res == 0 && str_is_zero(s) != 0)
		return (-1);
	itoa_res = ft_itoa(atoi_res);
	if (!itoa_res)
		return (1);
	simple_s = delete_surplus(s);
	if (!simple_s)
		return (free(itoa_res), 1);
	s = simple_s;
	if (ft_strcmp(itoa_res, s))
		return (free(simple_s), free(itoa_res), 1);
	return (free(itoa_res), free(simple_s), 0);
}

/*
 * Function: check_duplicate
 * -------------------------
 * Description:
 *   Checks for duplicate integer values in an array of strings. It assumes
 *   that the strings have been normalized (e.g. no extra leading zeros or
 *   signs) before the check.
 *
 * Parameters:
 *   - char **tab: The array of string representations of integers.
 *
 * Behavior:
 *   1. Iterates over the array using a nested loop.
 *   2. Converts each pair of strings to integers using ft_atoi.
 *   3. If any two converted integers are equal, returns 1.
 *   4. Returns 0 if no duplicates are found.
 *
 * Returns:
 *   - 1 if a duplicate is detected.
 *   - 0 if all elements are unique.
 */
static int	check_duplicate(char **tab)
{
	int	i;
	int	j;

	i = -1;
	while (tab[++i])
	{
		j = i;
		while (tab[++j])
		{
			if (ft_atoi(tab[i]) == ft_atoi(tab[j]))
				return (1);
		}
	}
	return (0);
}

/*
 * Function: parsing_check
 * -------------------------
 * Description:
 *   Validates an array of input strings by performing multiple checks:
 *     a. Validates each string's digit format using
 *        check_if_valid_digit.
 *     b. Verifies that each string represents an integer within range by
 *        calling check_int_overflow.
 *     c. Checks for duplicate numbers using check_duplicate.
 *
 * Parameters:
 *   - char **list: The array of input strings.
 *
 * Behavior:
 *   1. Returns an error if the list is NULL or empty.
 *   2. Iterates through each string and validates its digit format.
 *      If any string fails, prints "Error" to stderr and returns 1.
 *   3. Iterates again to check for integer overflow in each string.
 *      On failure, prints "Error" to stderr and returns 1.
 *   4. Checks for duplicate values. If duplicates are found, prints
 *      "Error" to stderr and returns 1.
 *   5. Returns 0 if all checks pass successfully.
 *
 * Returns:
 *   - 0 if all inputs are valid.
 *   - 1 if any validation error is detected.
 */
int	parsing_check(char **list)
{
	int	i;

	if (!list)
		return (1);
	if (!list[0])
		return (ft_putstr_fd("Error\n", 2), 1);
	i = -1;
	while (list[++i])
	{
		if (check_if_valid_digit(list[i]))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	i = -1;
	while (list[++i])
	{
		if (check_int_overflow(list[i]))
			return (ft_putstr_fd("Error\n", 2), 1);
	}
	if (check_duplicate(list))
		return (ft_putstr_fd("Error\n", 2), 1);
	return (0);
}
