/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:51:38 by hstander          #+#    #+#             */
/*   Updated: 2017/07/31 15:16:32 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "./libft/libft.h"

typedef	struct s_room	t_room;



struct					s_room
{
	char				*name;
	int					start;
	int					end;
	int					full;
	t_room				*room[100];
};


#endif
