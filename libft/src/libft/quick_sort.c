/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:45:31 by msabre            #+#    #+#             */
/*   Updated: 2020/01/17 19:56:41 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		quick_sort(int *stack, int l, int r)
{
	int		low;
	int		high;
	int		median;

	low = r;
	high = l;
	median = stack[(low + high) / 2];
	while (high <= low)
	{
		while (stack[high] < median)
			high++;
		while (stack[low] > median)
			low--;
		if (high <= low)
			ft_swap(stack, high++, low--);
	}
	if (l < low)
		quick_sort(stack, l, low);
	if (r > high)
		quick_sort(stack, high, r);
}
