/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:56:09 by msabre            #+#    #+#             */
/*   Updated: 2019/12/27 18:17:50 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

static char			**malloc_double_mass(char const *str, char c)
{
	char		**words;
	int			high_val;

	if ((high_val = count_words(str, c)) == 0)
		return (NULL);
	if (!(words = (char**)malloc(sizeof(char*) * (high_val + 1))))
		return (NULL);
	words[high_val] = NULL;
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**words;
	int			i;
	int			j;

	i = 0;
	words = malloc_double_mass(s, c);
	while (*s != '\0')
	{
		j = 0;
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		if (!(words[i] = (char*)malloc(sizeof(char)
			* word_len(s, c) + 1)))
		{
			free_doub_lvl_mass((void**)words);
			return (NULL);
		}
		while (*s != c)
			words[i][j++] = *s++;
		words[i][j] = '\0';
		i++;
	}
	return (words);
}
