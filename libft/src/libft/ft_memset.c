/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:59:12 by msabre            #+#    #+#             */
/*   Updated: 2019/10/30 22:50:53 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		*ft_memset(void *memptr, int val, size_t num)
{
	size_t i;

	i = 0;
	while (i < num)
	{
		((unsigned char*)memptr)[i] = val;
		i++;
	}
	return (memptr);
}
