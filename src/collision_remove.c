/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:37:24 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:26:03 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_rlst	*copy_path(t_rlst *path)
{
	t_rlst		*copy;
	int			num;

	copy = NULL;
	if (!path)
		return (NULL);
	num = path->path_number;
	while (path)
	{
		lst_rooms(&copy, path->room_pointer, 0, 0);
		path = path->next;
	}
	copy->path_number = num;
	return (copy);
}

int				collisions_rem(t_general *all)
{
	t_rlst		*source;
	t_rlst		*verifiable;
	t_rlst		*copy;
	int			i;

	i = 0;
	source = all->collision.array[i];
	verifiable = all->paths.array[all->paths.index - 1];
	while (i < all->collision.index)
	{
		copy = copy_path(source);
		all->paths_copies.add_doub(&all->paths_copies, copy);
		all->cm_len -= length_path(source);
		rm_common_edges(source, verifiable);
		split_in_out(source->next, all->end);
		split_in_out(verifiable->next, all->end);
		verifiable = source;
		source = all->collision.array[++i];
	}
	return (i);
}
