/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:06:19 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:45:08 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		start_end_output(t_general *all)
{
	int			i;

	i = 1;
	while (i <= all->cn_ants)
		ft_printf("L%d-end ", i++);
	write(1, "\n", 1);
	rooms_free(&all->rooms);
	free(all->coor.array);
	if (all->links_r.array)
		all->links_r.arr_del(&(all->links_r));
}

static void		map_output(t_general *all)
{
	int			i;

	i = 0;
	if (!all->flags.m && !all->flags.p && !all->flags.t)
	{
		while (i < all->map_output.index)
			ft_printf("%s\n", (char *)all->map_output.array[i++]);
		write(1, "\n", 1);
	}
	all->map_output.arr_del(&(all->map_output));
}

static void		unvalid_free(t_general *all)
{
	rooms_free(&all->rooms);
	free(all->coor.array);
	if (all->links_r.array)
		all->links_r.arr_del(&(all->links_r));
	if (all->map_output.result)
		ft_printf("Line %d: ", all->map_output.result);
	ft_printf("%s", all->error_message);
	all->map_output.arr_del(&(all->map_output));
}

static void		general_initial(t_general *all)
{
	init(&all->coor, 200);
	init(&all->rooms, 200);
	init(&all->map_output, 200);
	all->links_r.array = NULL;
	all->error_message = NULL;
	all->paths.array = NULL;
	all->start = NULL;
	all->end = NULL;
	all->cn_ants = 0;
}

int				start_solution(t_general *all)
{
	general_initial(all);
	if (!valid(all))
	{
		unvalid_free(all);
		return (-1);
	}
	map_output(all);
	if (search_link(all->start->links, all->end))
	{
		start_end_output(all);
		return (1);
	}
	else
	{
		if (!lem_in(all))
			return (-1);
	}
	free_content(all);
	return (1);
}
