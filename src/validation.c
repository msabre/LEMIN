/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:08:46 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:49:21 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	no_rooms_or_links(t_general *all)
{
	if (!all->rooms.index)
	{
		all->map_output.result = 0;
		all->error_message = "no rooms\n";
	}
	else if (!all->links_r.array)
	{
		all->map_output.result = 0;
		all->error_message = "no links\n";
	}
}

static int	check_map_line(t_general *all, char *line)
{
	if (is_empty(line, &all->error_message))
	{
		free(line);
		return (0);
	}
	else if (is_room(line, all))
		new_room(line, all->coor.array[all->coor.index - 1], &(all->rooms));
	else if (line[0] == '#')
	{
		if (!check_hash(&line, all))
			return (0);
	}
	else if (is_link(line, &all->error_message) == 1)
	{
		if (!get_graph(all, line))
			return (0);
		return (2);
	}
	else
		return (invalid_room(all, line));
	return (1);
}

int			valid(t_general *all)
{
	char	*line;
	int		result;

	find_ants_count(all);
	if (all->cn_ants < 1)
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		result = check_map_line(all, line);
		if (!result)
			return (0);
		if (result == 2)
			return (1);
	}
	no_rooms_or_links(all);
	return (0);
}
