/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:34:06 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 13:58:29 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

void		ft_memswap(void **array, int i, int j)
{
	void	*tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
