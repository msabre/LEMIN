/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:05:20 by msabre            #+#    #+#             */
/*   Updated: 2019/11/27 14:12:14 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# include "libft.h"

typedef	struct		s_gnlist
{
	char			*content;
	int				content_size;
	struct s_gnlist	*next;
}					t_gnlist;

void				ft_lstadd(t_gnlist **alst, t_gnlist *new);
int					get_next_line(const int fd, char **line);

#endif
