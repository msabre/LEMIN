/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:26:09 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:58:51 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		link_to_unknow_room(t_general *all,
				char **links, char *tmp, int j)
{
	all->error_message = "link to unknow room\n";
	tmp--;
	*tmp = '-';
	all->map_output.result = search_mem(links[j],
		all->map_output.array, all->map_output.index, 0) + 1;
	return (0);
}

static int		bynary_find_rooms(t_room **array, char *search, int high)
{
	int			low;
	int			res;
	int			mid;

	low = 0;
	while (low <= high)
	{
		mid = (high + low) / 2;
		if ((res = ft_strcmp(array[mid]->name, search)) == 0)
			return (mid);
		if (res > 0)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return (-1);
}

static void		add_links(t_general *all, int first, int second)
{
	t_rlst		*links;

	if (all->rooms.array[first] == all->rooms.array[second])
		return ;
	links = ((t_room*)all->rooms.array[first])->links;
	if (search_link(links, all->rooms.array[second]))
		return ;
	links = ((t_room*)all->rooms.array[second])->links;
	if (search_link(links, all->rooms.array[first]))
		return ;
	lst_rooms(&((t_room *)all->rooms.array[first])->links,
		all->rooms.array[second], 1, 1);
	lst_rooms(&((t_room *)all->rooms.array[second])->links,
		all->rooms.array[first], 1, 1);
}

int				set_links(char **links, int size, t_general *all)
{
	char		*tmp;
	int			first;
	int			second;
	int			j;

	j = -1;
	while (++j < size)
	{
		tmp = ft_strchr(links[j], '-');
		*tmp = '\0';
		tmp++;
		if ((first = bynary_find_rooms((t_room **)all->rooms.array,
			tmp, all->rooms.index - 1)) < 0)
			return (link_to_unknow_room(all, links, tmp, j));
		if ((second = bynary_find_rooms((t_room **)all->rooms.array,
			links[j], all->rooms.index - 1)) < 0)
			return (link_to_unknow_room(all, links, tmp, j));
		add_links(all, first, second);
	}
	return (1);
}
