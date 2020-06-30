/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:02:20 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 18:23:07 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_link(char *line, char **error)
{
	int			i;

	i = 0;
	if (line[0] == '#')
	{
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		{
			*error = "start and end rooms must be in one copy\n";
			return (0);
		}
		return (2);
	}
	if (*line == '\0')
		*error = "empty line\n";
	if (count_words(line, ' ') != 1)
		return (0);
	while (line[i] != '-' && line[i] != '\0')
		i++;
	if (line[i] != '-')
		return (0);
	return (1);
}
