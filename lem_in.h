/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:51:38 by hstander          #+#    #+#             */
/*   Updated: 2017/08/11 17:07:16 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libft/libft.h"

typedef	struct s_room	t_room;

struct					s_room
{
	char				*name;
    char                *flag;
	int					start;
	int					end;
	char				ant;
	int					full;
	int					visit;
	t_room				*room[10000];
};

typedef struct			s_args
{
	t_room				*rooms[10000];
	char				*line;
	char				**args;
	char				**links;
}						t_args;

typedef struct			s_vars
{
	int					start;
	int					end;
	int					r_i;
	int					b_i;
	int					e_i;
	int					cntr;
	int					ants;
}						t_vars;

typedef struct			s_path
{
	char				*data;
	struct s_path		*next;
}						t_path;

typedef struct			s_ant
{
	char				*name;
	char				*path;
	int					index;
}						t_ant;
void					ft_frees(t_args *ag);
void					ft_rooms(t_vars *vs, t_args *ag);
void					ft_links(t_vars *vs, t_args *ag);
void					ft_startend(t_vars *vs, t_args *ag);
void					ft_datastruct(t_vars *vs, t_args *ag);

#endif
