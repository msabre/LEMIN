/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 19:17:25 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:04:30 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		get_turnline(char **dst, char *name, int ant)
{
	char		*turn_line;
	int			common_len;
	int			ant_len;
	int			i;

	ant_len = cn_power(ant);
	common_len = 4 + ft_strlen(name) + ant_len;
	turn_line = (char*)ft_memalloc(sizeof(char) * common_len);
	if (!turn_line)
		exit(-1);
	turn_line[0] = 'L';
	i = ant_len;
	while (ant > 0)
	{
		turn_line[i--] = ant % 10 + '0';
		ant /= 10;
	}
	i = ant_len + 1;
	turn_line[i] = '-';
	ft_strlcat(turn_line, name, common_len);
	turn_line[common_len - 1] = ' ';
	*dst = turn_line;
	return (common_len);
}

void			print_turn(t_output *out)
{
	int			len;
	int			i;

	i = 0;
	booblesort(out->names.array, out->ants, out->a_index);
	while (i < out->a_index)
	{
		len = get_turnline(&out->turn_line, out->names.array[i], out->ants[i]);
		write(1, out->turn_line, len);
		free(out->turn_line);
		i++;
	}
	write(1, "\n", 1);
	zero_doub_lvl_mass(out->names.array, out->names.size);
}
