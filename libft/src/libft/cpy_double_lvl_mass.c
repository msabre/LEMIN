/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_double_lvl_mass.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 17:29:55 by msabre            #+#    #+#             */
/*   Updated: 2020/02/20 17:57:47 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void			cpy_double_lvl_mass(void **arr1, void **arr2, int size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		((char**)arr1)[i] = ((char**)arr2)[i];
		i++;
	}
}
