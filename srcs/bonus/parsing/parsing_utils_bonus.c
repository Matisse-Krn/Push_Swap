/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:13:32 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/21 04:15:19 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Find the real length of a number represented by a string :
 *		- "2147483647" = 10   ->   "0002147483647" = 10
 *		- "+78" = 2			  ->   "+0078" = 2
 *		- "0" = 1			  ->   -0" = 1
 * Because we use this in 'delete_surplus()' after treating the cases of "-000",
 *	  we can't have an input who 's' = "-0000" (or "+0", "-0", "+00",...)
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
 * Return 0 if the value of the int represented by 's' is 0 
 *	  ('+000', '-0000', '+0',...), or return 1
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
 * Delete all superfluous char :
 *		-	"0045"	 ->  "45"
 *		-	"-0045"  ->  "-45"
 *		-	"+45"	 ->  "45"
 *		-	"+0045"  ->  "45"
 *		-	"-0"	 ->  "0"
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
