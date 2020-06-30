/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_common_edges.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 14:33:10 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:03:21 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		discard_edges(t_rlst *source, t_rlst *verifiable)
{
	t_rlst		*tmp;

	tmp = verifiable->next;
	verifiable->next = source->next;
	(source->next)->prev = verifiable;
	source->next = tmp;
	tmp->prev = source;
}

static int		find_ends(t_rlst **source, t_rlst **verifiable)
{
	t_rlst		*st_src;
	t_rlst		*st_verif;
	int			count;

	st_src = *source;
	st_verif = *verifiable;
	count = pointers_to_extreme(source, verifiable);
	*verifiable = (*verifiable)->next;
	free_way_part(st_verif->next, count);
	st_verif->next = *verifiable;
	(*verifiable)->prev = st_verif;
	st_src = st_src->next;
	free_way_part((*source)->next, count);
	(*source)->next = st_src;
	st_src->prev = (*source);
	*verifiable = (*verifiable)->prev;
	discard_edges(*source, *verifiable);
	return (1);
}

void			rm_common_edges(t_rlst *source, t_rlst *verifiable)
{
	t_rlst		*start;
	t_room		*reader_p1;
	t_room		*reader_p2;

	while (source->next->next)
		source = source->next;
	start = verifiable->next;
	while (source && source->prev && source->prev->prev)
	{
		reader_p1 = source->room_pointer;
		while (verifiable->next->next)
		{
			reader_p2 = verifiable->room_pointer;
			if (reader_p1 == reader_p2)
				if (find_ends(&source, &verifiable) == 1)
					break ;
			verifiable = verifiable->next;
		}
		verifiable = start;
		source = source->prev;
	}
}
