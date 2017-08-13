/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:51:38 by hstander          #+#    #+#             */
/*   Updated: 2017/08/13 17:20:25 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libft/libft.h"
# include <fcntl.h>

typedef	struct s_room	t_room;
typedef struct s_args	t_args;
typedef struct s_vars	t_vars;
typedef struct s_path	t_path;
typedef	struct s_ant	t_ant;

struct					s_room
{
	char				*name;
	int					start;
	int					end;
	int					full;
	int					visit;
	t_room				*room[10000];
};

struct					s_args
{
	t_room				*rooms[10000];
	char				*line;
	char				**args;
	char				**links;
	t_ant				**ants_n;
	char				***paths;
};

struct					s_vars
{
	int					start;
	int					end;
	int					r_i;
	int					b_i;
	int					e_i;
	int					i;
	int					j;
	int					k;
	int					l;
	int					move;
	int					cntr;
	int					ants;
};

struct					s_path
{
	char				*data;
	struct s_path		*next;
};

struct					s_ant
{
	char				*name;
	char				*room;
	int					at_end;
	unsigned int		index;
};

void					ft_frees(t_args *ag);
void					ft_rooms(t_vars *vs, t_args *ag);
void					ft_links(t_vars *vs, t_args *ag);
void					ft_startend(t_vars *vs, t_args *ag);
void					ft_datastruct(t_vars *vs, t_args *ag);
void					ft_path_tofile(t_path *head, int fd);
void					ft_path(t_room *st, t_path *head, t_path *list, int fd);
size_t					ft_arrlen(char **arr);
void					ft_sort(char ***arr);
void					ft_start_end(t_vars *vs, t_args *ag);
void					ft_ant_names(t_vars *vs, t_args *ag);
void					ft_paths(t_vars *vs, t_args *ag);
void					ft_moveto(t_vars *vs, t_args *ag, int *loop_b);
int						ft_movefrom(t_vars *vs, t_args *ag);
void					ft_valid(t_vars *vs, t_args *ag, int *loop_b);
void					ft_roomloop(t_vars *vs, t_args *ag);
void					ft_pathloop(t_vars *vs, t_args *ag);
void					ft_antloop(t_vars *vs, t_args *ag);
void					ft_free_paths(t_args *ag);
void					ft_free_rooms(t_args *ag);
void					ft_free_ants(t_args *ag);
void					ft_exit(void);
int						ft_digit(t_args *ag);

#endif
