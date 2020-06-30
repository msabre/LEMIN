/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_qsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:30:26 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 13:38:27 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void			str_qsorts(char **array, int l, int r)
{
	int			low;
	int			high;
	char		*median;

	low = r;
	high = l;
	median = array[(low + high) / 2];
	while (high <= low)
	{
		while (ft_strcmp(array[high], median) < 0)
			high++;
		while (ft_strcmp(array[low], median) > 0)
			low--;
		if (high <= low)
			ft_memswap((void**)array, high++, low--);
	}
	if (l < low)
		str_qsorts(array, l, low);
	if (r > high)
		str_qsorts(array, high, r);
}
