/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:33 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:12:22 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		save_link(t_arraylist *map_output,
				t_arraylist *links, char *line, int res)
{
	char		*copy_link;

	copy_link = (res == 2) ? line : ft_strdup(line);
	map_output->add_doub(map_output, copy_link);
	if (map_output->result == -1)
		exit(-1);
	if (res == 1)
	{
		links->add_doub(links, (void *)line);
		if (links->result == -1)
			exit(-1);
	}
}

static int		save_links_by_strings(t_arraylist *map_output,
				t_arraylist *links, char **error)
{
	char		*line;
	int			res;

	while (get_next_line(0, &line) > 0)
	{
		if (!line || *line == '\0')
		{
			free(line);
			return (put_error(error, &(map_output->result),
				"empty line\n", map_output->index + 1));
		}
		res = is_link(line, error);
		if (!res)
		{
			free(line);
			return (put_error(error, &(map_output->result),
				"invalid link\n", map_output->index + 1));
		}
		save_link(map_output, links, line, res);
	}
	return (1);
}

static int		form_map_of_rooms(t_general *all, char *firstlink)
{
	if (!search_same_rooms(all))
	{
		free(firstlink);
		return (0);
	}
	if (!search_same_coor(all))
	{
		free(firstlink);
		return (0);
	}
	init(&all->links_r, all->rooms.index);
	all->links_r.add_doub(&all->links_r, (void*)firstlink);
	if (all->links_r.result == -1)
		exit(-1);
	if (!save_links_by_strings(&all->map_output,
		&(all->links_r), &all->error_message))
		return (0);
	if (!search_same_links(all))
		return (0);
	if (!set_links((char**)all->links_r.array,
		all->links_r.index, all))
		return (0);
	return (1);
}

int				get_graph(t_general *all, char *firstlink)
{
	all->map_output.add_doub(&all->map_output, ft_strdup(firstlink));
	if (!all->rooms.index)
	{
		all->map_output.result = 0;
		all->error_message = "no rooms\n";
		free(firstlink);
		return (0);
	}
	if (!all->start || !all->end)
	{
		free(firstlink);
		all->map_output.result = 0;
		if (!all->start && !all->end)
			all->error_message = "no start, no end\n";
		else
			all->error_message =
				(!all->end) ? "no end room\n" : "no start room\n";
		return (0);
	}
	if (!form_map_of_rooms(all, firstlink))
		return (0);
	return (1);
}
