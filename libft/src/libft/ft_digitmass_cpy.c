/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digitmass_cpy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 22:23:39 by msabre            #+#    #+#             */
/*   Updated: 2019/11/27 22:34:23 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int			*ft_digitmass_cpy(int *stack, int size)
{
	int		*s_a;
	int		i;

	i = 0;
	s_a = NULL;
	s_a = (int*)malloc(sizeof(int) * size);
	if (!s_a)
		return (NULL);
	while (i < size)
	{
		s_a[i] = stack[i];
		i++;
	}
	return (s_a);
}
