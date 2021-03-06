/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:32:17 by msabre            #+#    #+#             */
/*   Updated: 2019/12/28 13:49:07 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		ft_isalnum(int c)
{
	if (c >= 65 && c <= 90)
		return (2);
	if (c >= 97 && c <= 122)
		return (2);
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
