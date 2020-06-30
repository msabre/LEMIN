/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:02:12 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 19:59:10 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			booblesort(void **paths, int *p_cn, int size)
{
	void		*tmp;
	int			i;
	int			j;

	i = size - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (p_cn[j] > p_cn[j + 1])
			{
				ft_swap(p_cn, j, j + 1);
				tmp = paths[j];
				paths[j] = paths[j + 1];
				paths[j + 1] = tmp;
			}
			j++;
		}
		i--;
	}
}

int				*sort_paths(t_rlst **paths, int size)
{
	int			*p_cn;
	int			i;

	i = 0;
	p_cn = (int*)malloc(sizeof(int) * size);
	if (!p_cn)
	{
		free_paths(paths, size);
		return (NULL);
	}
	while (i < size)
	{
		p_cn[i] = length_path(paths[i]);
		i++;
	}
	booblesort((void**)paths, p_cn, size);
	return (p_cn);
}
