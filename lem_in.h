/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/15 15:24:04 by mkaliber          #+#    #+#             */
/*   Updated: 2017/06/15 15:24:06 by mkaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LEM_IN_H
# define __LEM_IN_H
# define COMMENT 1
# define ROOM 2
# define CONNECT 3
# define NOANTS 4
# define START 5
# define END 6
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

typedef	struct	s_p
{
	int			index;
	struct s_p	*next;
}				t_path;

typedef struct	s_room
{
	int			index;
	char		*name;
	int			x;
	int			y;
	int			check;
}				t_room;

typedef	struct	s_home
{
	int			res;
	int			start;
	int			end;
	int			gx;
	int			gy;
	int			count_ants;
	int			count_room;
	int			count_path;
	t_room		**rooms;
	t_list		*path;
	char		*map;
	char		*str_temp;
	int			**matrix;
	int			f_u;
	int			f_c;
	int			f_p;
}				t_home;

t_home			g_l;

char			*ft_strjoinf(char *s1, char const *s2);
int				ft_check_count(char *str);
void			add_map(void);
void			check_room(void);
void			check_connection(void);
void			ft_error(char *error);
int				count_split(char **str);
void			free_array_char(char **str);
void			ft_init_matrix(void);
void			parse_connect(void);
void			validate_connect(void);
void			ft_addlist_path(t_path **lst, int index);
void			ft_lstdelback(t_path **list);
int				path_size(t_path *tmp);
int				find_path(t_path **tmp_path, int curr);
void			print_res(t_path *room, int name);
void			pint_ant(t_path *room, int name, int *ch);
void			pint_ant_col(t_path *room, int name, int *ch);
void			check_usage(int ac, char **av);
void			print_all_path(void);
void			output(t_path *room);
t_path			*min_path();

#endif
