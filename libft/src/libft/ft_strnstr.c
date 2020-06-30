/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:33:19 by msabre            #+#    #+#             */
/*   Updated: 2019/10/30 23:00:57 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/libft.h"

char		*ft_strnstr(const char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*src == '\0')
		return ((char*)dst);
	while (dst[i])
	{
		j = 0;
		while (src[j])
		{
			if (dst[i + j] == src[j] && (i + j) < len)
				j++;
			else
				break ;
			if (src[j] == '\0')
				return ((char*)dst + i + j - ft_strlen(src));
		}
		i++;
	}
	return (NULL);
}
