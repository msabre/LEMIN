/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:26:29 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:49:17 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		get_changes(t_rlst **paths, t_output *out, int size_p)
{
	t_rlst		*ptr;
	int			i;

	i = 0;
	while (i < size_p)
	{
		ptr = paths[i]->next;
		while (ptr->next)
		{
			if (((t_room*)ptr->room_pointer)->ant != 0)
			{
				out->ants[(out)->a_index++] =
					((t_room*)ptr->room_pointer)->ant;
				out->names.add_doub(&out->names,
					((t_room*)ptr->room_pointer)->name);
				if (out->names.result == -1)
					exit(-1);
			}
			ptr = ptr->next;
		}
		i++;
	}
}

static void		push_to_reveral_ways(t_general *all,
				t_rlst **paths, int *p_cn, long *curr)
{
	t_room		*ptr;
	int			res;
	int			i;
	int			j;

	i = 0;
	while (i < all->paths.index)
	{
		ptr = (paths[i])->next->room_pointer;
		j = i - 1;
		res = 0;
		while (j >= 0)
			res += p_cn[i] - p_cn[j--];
		if (all->cn_ants < res)
			break ;
		ptr->ant = *curr;
		(*curr)++;
		(all->cn_ants)--;
		if (all->cn_ants == 0)
			break ;
		i++;
	}
}

static int		put_in_the_way(t_general *all, t_output *out, int *p_cn)
{
	t_rlst		**paths;
	int			count;
	long		curr;

	curr = 1;
	count = 0;
	paths = (t_rlst **)all->paths.array;
	push_to_reveral_ways(all, paths, p_cn, &curr);
	while (out->finished < out->balance)
	{
		if (all->flags.t == 0)
		{
			get_changes(paths, out, all->paths.index);
			print_turn(out);
		}
		out->a_index = 0;
		out->names.index = 0;
		step_one(paths, out, all->end, all->paths.index);
		if (all->cn_ants > 0)
			push_to_reveral_ways(all, paths, p_cn, &curr);
		count++;
	}
	if (all->flags.t == 0)
		print_turn(out);
	return (count + 1);
}

int				let_ants_go(t_general *all, int *p_cn)
{
	t_output	out;
	int			count;

	if (!p_cn)
		return (0);
	out.balance = all->cn_ants;
	out.finished = 0;
	out.a_index = 0;
	out.a_size = p_cn[all->paths.index - 1] * 20;
	init(&out.names, out.a_size);
	out.ants = (int*)malloc(sizeof(int) * out.a_size);
	count = put_in_the_way(all, &out, p_cn);
	if (all->flags.t)
	{
		zero_doub_lvl_mass(out.names.array, out.names.size);
		ft_printf("#\n# Total turns: %d\n#\n", count);
	}
	out.names.arr_del(&out.names);
	free(out.ants);
	free(p_cn);
	return (1);
}
