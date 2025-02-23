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
 * Check if the element 's' :
 *		- is only constitute by a single '-' or '+' sign at the beginning,
*		and only digits char after
 *		- is not only a single '+' or '-' without anything else
 * Return 0 if the element is valid, return -1 if NULL str is passed to,
 *		otherwise return 1
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
 * Convert string to integer with 'ft_atoi()' -> 'atoi_res'
 * Convert 'atoi_res' to string with 'ft_itoa()' -> 'itoa_res'
 * Normalize element (“+00045” -> “45”,...), and compare with 'itoa_res'
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
 * Verify if an element is duplicate in the array
 * Because we use this function after 'delete_surplus()', we assure that initial
 *		strange formatted elements are normalized :
 *		"-0045" -> "-45"    |   "+045" -> "45"   |   "+78" -> "78"
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
 * Calls 'check_if_valid_digit()' for each element,
 * Then checks if each element is contained in an INT or if it is overflow,
 * Then checks that there are no duplicate elements in the 'list'.
 *
 * Returns 1 if overflow, 0 otherwise
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
