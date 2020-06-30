/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:00:06 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 14:00:25 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int			is_numvalue(char *str)
{
	int		count;
	int		sign;

	count = 0;
	sign = 0;
	if (*str == '-')
	{
		sign = 1;
		count++;
		str++;
	}
	while (*str && is_num(*str))
	{
		count++;
		str++;
	}
	if ((*str != ' ' && *str) || (sign && count == 1) || count > 10)
		return (0);
	return (count);
}
