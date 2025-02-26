/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:38:22 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/17 21:56:14 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Function: real_length
 * ---------------------
 * Description:
 *   Computes the effective length of a numeric string by skipping a
 *   leading '+' sign and any leading zeros. If a '-' sign is present,
 *   it is counted as a character.
 *
 * Parameters:
 *   - char *s: The input numeric string.
 *
 * Behavior:
 *   1. If the string starts with a '+', it is skipped.
 *   2. If the string starts with a '-', it is counted and skipped.
 *   3. Leading zeros are then skipped.
 *   4. The remaining digits are counted to obtain the real length.
 *
 * Returns:
 *   - The effective length of the number as an integer.
 */
int	real_length(char *s)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (s[i] == '+')
		i++;
	if (s[i] == '-')
	{
		len++;
		i++;
	}
	while (s[i] == '0')
		i++;
	while (s[i++])
		len++;
	return (len);
}

/*
 * Function: str_is_zero
 * ---------------------
 * Description:
 *   Determines whether the numeric string represents the value zero.
 *   It treats strings like "+000", "-0000", or "0" as zero.
 *
 * Parameters:
 *   - char *s: The input numeric string.
 *
 * Behavior:
 *   1. Skips an initial '+' or '-' sign.
 *   2. Skips all subsequent '0' characters.
 *   3. If the end of the string is reached, the number is zero.
 *
 * Returns:
 *   - 0 if the string represents zero.
 *   - 1 otherwise.
 */
int	str_is_zero(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	if (!s[i])
		return (0);
	return (1);
}

/*
 * Function: write_real_str
 * ------------------------
 * Description:
 *   Writes a normalized version of the numeric string into the
 *   destination buffer. It omits any unnecessary leading '+' or zeros,
 *   while preserving a '-' sign if present.
 *
 * Parameters:
 *   - char *dst: The destination buffer where the normalized string
 *                is written.
 *   - char *s: The original numeric string.
 *
 * Behavior:
 *   1. Checks if the string begins with '+' or '-'. A '-' is kept;
 *      a '+' is skipped.
 *   2. Skips all leading zeros.
 *   3. Copies the remaining digits into the destination buffer.
 *
 * Returns:
 *   - This is a void function; the result is stored in dst.
 */
static void	write_real_str(char *dst, char *s)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			dst[j++] = '-';
		i++;
	}
	while (s[i] == '0')
		i++;
	while (s[i])
		dst[j++] = s[i++];
}

/*
 * Function: delete_surplus
 * ------------------------
 * Description:
 *   Removes superfluous characters from a numeric string. This
 *   function normalizes the string by eliminating extra zeros and an
 *   unnecessary '+' sign.
 *
 * Parameters:
 *   - char *s: The input numeric string.
 *
 * Behavior:
 *   1. If the string represents zero (e.g. "+000", "-0000"), allocates
 *      a new string containing "0".
 *   2. Otherwise, computes the real length of the normalized string.
 *   3. Allocates a new string of the computed length.
 *   4. Uses write_real_str() to fill the new string with the normalized
 *      numeric value.
 *
 * Returns:
 *   - A newly allocated, normalized string.
 *   - NULL if memory allocation fails.
 */

char	*delete_surplus(char *s)
{
	int		len;
	char	*dst;

	if (str_is_zero(s) == 0)
	{
		dst = ft_calloc(2, sizeof(char));
		if (!dst)
			return (NULL);
		return (dst[0] = '0', dst);
	}
	len = real_length(s);
	dst = ft_calloc(len + 1, sizeof(char));
	if (!dst)
		return (NULL);
	write_real_str(dst, s);
	return (dst);
}

/*
 * Function: convert_str_to_tab
 * ----------------------------
 * Description:
 *   Converts an array of numeric strings into an array of integers.
 *   It also determines the number of elements in the input array.
 *
 * Parameters:
 *   - char **s: The array of numeric strings.
 *   - int *len: Pointer to an integer that will hold the number of
 *               elements.
 *
 * Behavior:
 *   1. Counts the number of strings in the input array and updates *len.
 *   2. Allocates an integer array of size *len.
 *   3. Converts each string to an integer using ft_atoi.
 *
 * Returns:
 *   - A pointer to the integer array if successful.
 *   - NULL if the input is invalid or if allocation fails.
 */
int	*convert_str_to_tab(char **s, int *len)
{
	int	i;
	int	*tab;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
		;
	*len = i;
	if (*len <= 0)
		return (NULL);
	tab = ft_calloc(*len, sizeof(int));
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < *len)
		tab[i] = ft_atoi(s[i]);
	return (tab);
}
