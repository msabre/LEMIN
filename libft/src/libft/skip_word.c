/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:04:15 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 14:04:47 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int		skip_word(char *str, int in, int count)
{
	while (count > 0 && str[in] != '\0')
	{
		while ((str[in] == ' ' || str[in] == '\t') && str[in] != '\0')
			in++;
		while (str[in] != ' ' && str[in] != '\t' && str[in] != '\0')
			in++;
		count--;
	}
	return (in);
}
