/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerrien <mkerrien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 01:39:25 by mkerrien          #+#    #+#             */
/*   Updated: 2025/02/18 01:43:58 by mkerrien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = atoi(argv[1]);
		while (i > 0)
		{
			printf("%d ", i);
			i--;
		}
	}
	return (0);
}
