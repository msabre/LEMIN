/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:46:38 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:28:08 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		add_start_end(t_general *all, char *line, char *remeber_room)
{
	new_room(line, all->coor.array[all->coor.index - 1], &(all->rooms));
	if (ft_strcmp(remeber_room, "##start") == 0)
	{
		if (all->start)
		{
			all->error_message = "start and end rooms must be in one copy\n";
			all->map_output.result = all->map_output.index + 1;
			return (0);
		}
		all->start = all->rooms.array[all->rooms.index - 1];
	}
	else
	{
		if (all->end)
		{
			all->error_message = "start and end rooms must be in one copy\n";
			all->map_output.result = all->map_output.index + 1;
			return (0);
		}
		all->end = all->rooms.array[all->rooms.index - 1];
	}
	return (1);
}

static char		*skip_comments(t_general *all)
{
	char		*line;

	line = NULL;
	get_next_line(0, &line);
	if (*line != '#')
		return (line);
	else
		all->map_output.add_doub(&all->map_output, line);
	while (line && line[0] == '#')
	{
		if (ft_strcmp(line, "##start") == 0 || ft_strcmp(line, "##end") == 0)
		{
			put_error(&all->error_message, &(all->map_output.result),
				"start and end the same\n", all->map_output.index + 1);
			return (NULL);
		}
		get_next_line(0, &line);
		if (*line && line[0] != '#')
			return (line);
		else
			all->map_output.add_doub(&all->map_output, line);
		if (all->map_output.result == -1)
			exit(-1);
	}
	return (line);
}

static int		start_end_commands(t_general *all, char *line)
{
	char		*remeber_room;
	char		*output;

	remeber_room = line;
	if (!(line = skip_comments(all)))
		return (0);
	if (is_room(line, all))
	{
		if (!add_start_end(all, line, remeber_room))
			return (0);
	}
	else
	{
		free(line);
		output = (ft_strcmp("##start", remeber_room) == 0)
			? "invalid start room\n" : "invalid end room\n";
		return (put_error(&all->error_message, &(all->map_output.result),
			output, all->map_output.index + 1));
	}
	return (1);
}

int				check_hash(char **line, t_general *all)
{
	all->map_output.add_doub(&all->map_output, *line);
	if (all->map_output.result == -1)
		exit(-1);
	if ((*line)[1] == '#')
	{
		if ((*line)[2] == '#')
			return (1);
		if (ft_strcmp(*line, "##start") == 0 || ft_strcmp(*line, "##end") == 0)
		{
			if (!start_end_commands(all, *line))
				return (0);
		}
	}
	return (1);
}
