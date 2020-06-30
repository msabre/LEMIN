/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:44:50 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:07:58 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				invalid_room(t_general *all, char *line)
{
	free(line);
	all->map_output.result = all->map_output.index + 1;
	if (!all->error_message)
		all->error_message = "invalid room\n";
	return (0);
}

static int		check_room_format(char **line, char **error, char **tmp)
{
	int			res;

	if (!(*line) && count_words(*line, ' ') != 3)
		return (0);
	*tmp = *line;
	if (!(*line = ft_strchr((*line), ' ')))
		return (0);
	*line += 1;
	if (!(res = is_numvalue(*line)))
	{
		*error = "error room's coordination\n";
		return (0);
	}
	res += 1;
	if (!(res = is_numvalue((*line) + res)))
	{
		*error = "error room's coordination\n";
		return (0);
	}
	return (1);
}

int				is_room(char *line, t_general *all)
{
	char		*room_copy;
	char		*tmp;

	if (is_empty(line, &all->error_message))
		return (0);
	if (*line == 'L')
	{
		all->error_message = "rooms name can't start by uppercase L\n";
		return (0);
	}
	if (!check_room_format(&line, &all->error_message, &tmp))
		return (0);
	room_copy = ft_strdup(tmp);
	all->map_output.add_doub(&all->map_output, room_copy);
	if (all->map_output.result == -1)
		exit(-1);
	tmp[line - tmp - 1] = '\0';
	all->coor.add_doub(&(all->coor), line);
	if (all->coor.result == -1)
		exit(-1);
	return (1);
}
