/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:18:03 by msabre            #+#    #+#             */
/*   Updated: 2019/12/27 18:18:34 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int				word_len(char const *str, char c)
{
	int			count;

	count = 0;
	while (*str != c)
	{
		str++;
		count++;
	}
	return (count);
}