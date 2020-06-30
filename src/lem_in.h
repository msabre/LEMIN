/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msabre <msabre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 15:12:06 by msabre            #+#    #+#             */
/*   Updated: 2020/02/29 20:49:42 by msabre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/headers/libft.h"
# include <stdarg.h>

typedef struct			s_arraylist
{
	void				**array;
	int					size;
	int					index;
	int					start_mem;
	int					searh_res;
	int					result;
	int					(*get_mem)(struct s_arraylist *);
	int					(*add_doub)(struct s_arraylist *, void *);
	void				(*lzero)(struct s_arraylist *);
	void				(*arr_del)(struct s_arraylist *);
	void				(*init)(struct s_arraylist *, int);
}						t_arraylist;

typedef struct			s_rlst
{
	void				*room_pointer;
	int					path_number;
	int					cost;
	int					access;
	struct s_rlst		*next;
	struct s_rlst		*prev;
}						t_rlst;

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	int					ant;
	int					split;
	int					length;
	int					searched;
	struct s_room		*in;
	struct s_room		*out;
	struct s_room		*parent;
	t_rlst				*links;
	void				*affiliation;
}						t_room;

typedef struct			s_flags
{
	int					t;
	int					p;
	int					h;
	int					i;
	int					m;
}						t_flags;

typedef struct			s_general
{
	t_arraylist			paths;
	t_arraylist			paths_copies;
	t_arraylist			collision;
	t_arraylist			links_r;
	t_arraylist			rooms;
	t_arraylist			coor;
	t_arraylist			queue;
	t_arraylist			map_output;
	t_flags				flags;
	t_room				*start;
	t_room				*end;
	char				*error_message;
	long				actual;
	int					cm_len;
	long				cn_ants;
}						t_general;

typedef struct			s_output
{
	t_arraylist			names;
	int					*ants;
	int					a_size;
	int					a_index;
	char				*turn_line;
	long				finished;
	long				balance;
}						t_output;

int						launch_alg(t_general *all);
int						lst_rooms(t_rlst **list, t_room *new,
						int cost, int access);
int						belmonford_alg(t_general *all);
int						lem_in(t_general *all);
int						let_ants_go(t_general *all, int *p_cn);
void					free_paths(t_rlst **paths, int size);
void					free_way(t_rlst *path);
void					init(t_arraylist *arraylist, int start_mem);
int						add_to_tab_double_lvl(t_arraylist *arraylist,
						void *value);
void					lzero(t_arraylist *arraylist);
int						getmem(t_arraylist *arraylist);
t_rlst					*search_link(t_rlst *ln, t_room *searched);
void					str_qsorts(char **array, int l, int r);
void					booblesort(void **paths, int *p_cn, int size);
int						length_path(t_rlst *path);
int						start_solution(t_general *all);
void					find_ants_count(t_general *all);
int						valid(t_general *all);
int						is_room(char *line, t_general *all);
int						check_hash(char **line, t_general *all);
void					find_ants_count(t_general *all);
int						search_same_rooms(t_general *all);
int						search_same_coor(t_general *all);
int						search_same_links(t_general *all);
int						get_graph(t_general *all, char *firstlink);
void					free_content(t_general *all);
int						set_links(char **links, int size, t_general *all);
void					new_room(char *name, char *coordination,
						t_arraylist *array);
int						is_link(char *line, char **error);
int						is_empty(char *line, char **error);
int						search_mem(void *search, void **array,
						int size, int start);
int						put_error(char **put_error, int *put_line,
						char *error_message, int error_line);
int						collisions_rem(t_general *all);
void					free_way_part(t_rlst *path, int count);
void					rm_common_edges(t_rlst *source, t_rlst *verifiable);
int						split_in_out(t_rlst *path, t_room *end);
void					change_links(t_room **source, t_room *new_owner,
						t_rlst *link);
void					disconnect_link(t_room **room, t_rlst *link);
int						launch_alg(t_general *all);
t_rlst					*create_path(t_room *end);
void					collision_check(t_rlst *path, t_arraylist *collision);
void					info_refresh(t_general *all);
void					drop_bifurcations(t_room *room);
int						*sort_paths(t_rlst **paths,
						int size);
int						pointers_to_extreme(t_rlst **source,
						t_rlst **verifiable);
int						check_rooms_duplicates(t_room **array,
						int size);
int						check_duplicates(char **array, int size);
int						search_coor(t_arraylist *strings,
						char *search, int start);
void					rooms_free(t_arraylist *array);
int						invalid_room(t_general *all, char *line);
void					print_turn(t_output *out);
void					step_one(t_rlst **paths, t_output *out,
						t_room *end, int size);

#endif
