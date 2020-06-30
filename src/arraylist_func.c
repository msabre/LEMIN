/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 13:18:17 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:49:29 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void				lzero(t_arraylist *arraylist)
{
	int				i;

	i = 0;
	if (arraylist->index == 0)
		return ;
	while (i < arraylist->index)
		arraylist->array[i++] = NULL;
	arraylist->index = 0;
}

int					getmem(t_arraylist *arraylist)
{
	arraylist->array = (void**)ft_memalloc(sizeof(void*)
		* (arraylist->start_mem ? arraylist->start_mem : 10));
	if (!arraylist->array)
	{
		arraylist->result = -1;
		return (0);
	}
	arraylist->index = 0;
	arraylist->size = (arraylist->start_mem) ? arraylist->start_mem : 10;
	return (1);
}

void				del_arr(t_arraylist *arraylist)
{
	int				i;

	i = 0;
	while (i < arraylist->index)
	{
		free(arraylist->array[i]);
		i++;
	}
	free(arraylist->array);
	arraylist->size = 0;
	arraylist->index = 0;
}

int					add_to_tab_double_lvl(t_arraylist *arraylist, void *value)
{
	void		**new_mem;

	if (!arraylist->array)
		if (!getmem(arraylist))
			return ((arraylist->result = -1));
	if (arraylist->index == arraylist->size)
	{
		new_mem = (void**)ft_memalloc(sizeof(void*)
			* (arraylist->size * 2 + 1));
		if (!new_mem)
			return ((arraylist->result = -1));
		cpy_double_lvl_mass(new_mem, arraylist->array, arraylist->size);
		free(arraylist->array);
		arraylist->size *= 2;
		arraylist->array = new_mem;
	}
	arraylist->array[arraylist->index] = value;
	(arraylist->index)++;
	return ((arraylist->result = 1));
}

void				init(t_arraylist *arraylist, int start_mem)
{
	arraylist->start_mem = start_mem;
	arraylist->get_mem = &getmem;
	arraylist->lzero = &lzero;
	arraylist->add_doub = &add_to_tab_double_lvl;
	arraylist->arr_del = &del_arr;
	arraylist->start_mem = start_mem;
	if (!arraylist->get_mem(arraylist))
		arraylist->result = -1;
	else
		arraylist->result = 1;
}
