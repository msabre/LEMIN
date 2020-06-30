/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:09:25 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:00:30 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_empty(char *line, char **error)
{
	if (*line == '\0')
	{
		*error = "empty line\n";
		return (1);
	}
	return (0);
}

int			put_error(char **put_error, int *put_line,
				char *error_message, int error_line)
{
	*put_error = error_message;
	*put_line = error_line;
	return (0);
}

int			search_mem(void *search, void **array, int size, int start)
{
	int len;
	int	i;

	i = start;
	if (!array)
		return (-1);
	while (i < size)
	{
		len = ft_strlen((char *)search);
		if (ft_memcmp(array[i], search, len) == 0)
			break ;
		i++;
	}
	return (i);
}

int			search_coor(t_arraylist *strings, char *search, int start)
{
	char	*str;
	int		i;

	i = start;
	while (i < strings->index)
	{
		str = ft_strchr(strings->array[i], ' ');
		if (str)
		{
			str++;
			if (ft_strcmp(search, str) == 0)
				break ;
		}
		i++;
	}
	return (i);
}
