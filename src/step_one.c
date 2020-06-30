/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:19:03 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:49:18 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	let_ant_out(t_output *out, t_room *end, t_rlst *ptr)
{
	out->ants[(out->a_index)++] = ((t_room*)ptr->prev->room_pointer)->ant;
	out->names.add_doub(&out->names, end->name);
	((t_room*)ptr->prev->room_pointer)->ant = 0;
	(out->finished)++;
	ptr = ptr->prev;
}

void		step_one(t_rlst **paths, t_output *out, t_room *end, int size)
{
	t_rlst	*ptr;
	int		i;

	i = 0;
	while (i < size)
	{
		ptr = paths[i]->next;
		while (ptr->next)
			ptr = ptr->next;
		if (((t_room*)ptr->prev->room_pointer)->ant != 0)
			let_ant_out(out, end, ptr);
		while (ptr->prev)
		{
			if (((t_room*)ptr->prev->room_pointer)->ant)
			{
				((t_room*)ptr->room_pointer)->ant =
					((t_room*)ptr->prev->room_pointer)->ant;
				((t_room*)ptr->prev->room_pointer)->ant = 0;
			}
			ptr = ptr->prev;
		}
		i++;
	}
}
