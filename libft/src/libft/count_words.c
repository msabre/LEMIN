/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:17:17 by msabre            #+#    #+#             */
/*   Updated: 2019/12/27 18:17:44 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

int				count_words(char const *s, char c)
{
	int			count;
	int			j;

	j = 0;
	count = 0;
	while (s[j] != '\0')
	{
		while (s[j] == c && s[j] != '\0')
			j++;
		if (s[j] != c && s[j] != '\0')
			count++;
		while (s[j] != c && s[j] != '\0')
			j++;
	}
	return (count);
}
