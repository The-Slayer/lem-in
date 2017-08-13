/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 16:03:19 by hstander          #+#    #+#             */
/*   Updated: 2017/08/13 16:04:54 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_free_paths(t_args *ag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ag->paths[i])
	{
		j = 0;
		while (ag->paths[i][j])
		{
			free(ag->paths[i][j]);
			j++;
		}
		free(ag->paths[i]);
		i++;
	}
	free(ag->paths);
}

void	ft_free_rooms(t_args *ag)
{
	int	i;

	i = 0;
	while (ag->rooms[i])
	{
		free(ag->rooms[i]->name);
		free(ag->rooms[i]);
		i++;
	}
}

void	ft_free_ants(t_args *ag)
{
	int	i;

	i = 0;
	while (ag->ants_n[i])
	{
		free(ag->ants_n[i]->name);
		free(ag->ants_n[i]);
		i++;
	}
	free(ag->ants_n);
}
