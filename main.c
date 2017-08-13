/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 09:50:30 by hstander          #+#    #+#             */
/*   Updated: 2017/08/11 17:25:02 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
//#include "./libft/libft.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_path(t_room *start, t_path *head, t_path *list, int fd)
{
	int i;
	t_path *next;

	i = 0;
	list->next = (t_path *)ft_memalloc(sizeof(t_path));
	start->visit = 1;
	list->data = start->name;
	next = list->next;
	if (start->end == 1)
	{
		while (head && head->data)
		{
			write(fd, head->data, ft_strlen(head->data));
            write(fd, " ", 1);
			head = head->next;
		}
		write(fd, "\n", ft_strlen("\n"));
	}
	while (start->room[i] && start->end == 0)
	{
		if (start->room[i]->visit == 0)
		{
			ft_path(start->room[i], head, next, fd);
		}
		i++;
	}
	list->data = NULL;
	list = NULL;
	start->visit = 0;
}

size_t  ft_arrlen(char **arr)
{
    size_t  i;

    i = 0;
    while (arr[i])
        i++;
    return (i);
}


void	ft_sort(char ***arr)
{
	char **ptr;
	int i;
	int j;

	i = 0;
	j = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_arrlen(arr[i]) > ft_arrlen(arr[j]))
			{
				ptr = arr[i];
				arr[i] = arr[j];
				arr[j] = ptr;
			}
			j++;
		}
		i++;
	}
}
/*
void	ft_nextmove(t_ant *ant, char **paths)
{
	int		i;

	i = 0;
	while (paths[i])
	{
		if (paths[i][index], )
	}
}
*/

int		main(void)
{
	t_vars	vs;
	t_args	ag;
	t_ant	**ants_n;
	int		i;
	int		j;
	int		k;
	int	 	start;
	int		end;
	int		fd;

	j = 0;
	i = 0;
	k = 0;
	ft_bzero(&vs, sizeof(t_vars));
	ft_bzero(&ag, sizeof(t_args));
	ft_datastruct(&vs, &ag);
	
	ants_n = (t_ant **)ft_memalloc(sizeof(t_ant *) * (vs.ants + 1));

	start = 0;
	end = 0;
	while (i < vs.ants)
	{
		ants_n[i] = (t_ant *)ft_memalloc(sizeof(t_ant));
		ants_n[i]->name = ft_itoa(i + 1);
		ants_n[i]->index = 1;
        ants_n[i]->room = ag.rooms[start]->name;
        ants_n[i]->at_end = 0;
		i++;
	}
	i = 0;
	vs.r_i = 0;
	while (ag.rooms[start]->start == 0)
		start++;
	while (ag.rooms[end]->end == 0)
		end++;
	ag.rooms[start]->full = vs.ants;

	
	
	while (ag.rooms[i])
	{
		ag.rooms[i]->visit = 0;
		i++;
	}
	t_path *list;
	fd = open("path", O_RDWR);
	list = (t_path *)ft_memalloc(sizeof(t_path));
	ft_path(ag.rooms[start], list, list, fd);
	
	char	***paths;
	char	*line;
	
	close (fd);
	fd = open("path", O_RDWR);
	paths = (char ***)ft_memalloc(sizeof(char **) * 10000);
	line = NULL;
	while (get_next_line(fd, &line))
	{
		paths[j] = ft_strsplit(line, ' ');
		j++;
	}
	ft_sort(paths);
	j = 0;
/*	while (paths[j])
	{
        i = 0;
        while (paths[j][i])
        {
		    ft_putstr(paths[j][i]);
            i++;
        }
        ft_putchar('\n');
		j++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putchar('\n');
*/	close (fd);
    int l;
    int move;
    l = 0;
    move = 0;
    while (ag.rooms[end]->full < vs.ants)
    {
        j = 0;
        while (ants_n[j])
        {
            i = 0;
            if (ants_n[j]->at_end != 1)
            {
                while (paths[i])
                {
                    k = 0;
                    if (ants_n[j]->index < ft_arrlen(paths[i]))
                    {
                        while (ag.rooms[k])
                        {
                   // dprintf(2,"Test 1");
                    
                    //dprintf(2,"Test 2");
                            if ((ft_strcmp(paths[i][ants_n[j]->index], ag.rooms[k]->name) == 0) && (ft_strcmp(paths[i][ants_n[j]->index - 1], ants_n[j]->room) == 0))
                            {
                                if (ag.rooms[k]->full == 0 && ag.rooms[k]->end == 0)
                                {
                             /*   if (ag.rooms[k]->end == 1)
                                    ants_n[j]->at_end = 1;
                             */     ag.rooms[k]->full += 1;
                                    ants_n[j]->room = ag.rooms[k]->name;
                                    printf("L%s-%s ", ants_n[j]->name, ag.rooms[k]->name);
                    //dprintf(2,"Test 3");
                                    l = 0;
                                    move = 1;
                                    while (ag.rooms[l])
                                    {
                                        if (ft_strcmp(paths[i][ants_n[j]->index - 1], ag.rooms[l]->name) == 0)
                                        {
                                            ag.rooms[l]->full -= 1;
                                            break;
                                        }
                                        l++;
                                    }
                                    ants_n[j]->index += 1;
                                    break ;
                                }
                                else if (ag.rooms[k]->end == 1)
                                {
                                    ants_n[j]->at_end = 1;
                                    ag.rooms[k]->full += 1;
                                    ants_n[j]->room = ag.rooms[k]->name;
                                    printf("L%s-%s ", ants_n[j]->name, ag.rooms[k]->name);
                    //dprintf(2,"Test 3");
                                    l = 0;
                                    move = 1;
                                    while (ag.rooms[l])
                                    {
                                        if (ft_strcmp(paths[i][ants_n[j]->index - 1], ag.rooms[l]->name) == 0)
                                        {
                                            ag.rooms[l]->full -= 1;
                                            break;
                                        }
                                        l++;
                                    }
                                    ants_n[j]->index += 1;
                                    break ;
                                }
                            }
                            k++;
                        }
                    }
                    if (move == 1)
                    {
                        move = 0;
                        break ;
                    }
                    i++;
                }
            }
            j++;
        }
        printf("\n");
        //ft_putstr("\n");
    }

/*
	i = 0;
	j = 0;
    int test = 0;


	while (ag.rooms[end]->full < vs.ants)
	{
		while (ants_n[i] != '\0' && ants_n[i] == 'e')
			i++;
		j = 0;
		k = 1;
		while (ag.rooms[start]->room[j] && ag.rooms[start]->full > 0)
		{
			if (ag.rooms[start]->room[j]->full == 0)
			{
				if (ag.rooms[start]->room[j]->name == ag.rooms[end]->name)
				{
					ag.rooms[start]->room[j]->full += 1;
					ag.rooms[start]->full -= 1;
				}
				else
				{
					ag.rooms[start]->room[j]->full = 1;
					ag.rooms[start]->full -= 1;
				}
				ag.rooms[start]->room[j]->ant = ants_n[i];
				ants_n[i] = 'e';
				i++;
				printf("-->L%c-%s ", ag.rooms[start]->room[j]->ant, ag.rooms[start]->room[j]->name);
			}
			else if (ft_strequ(ag.rooms[start]->room[j]->name, ag.rooms[end]->name))
			{
				ag.rooms[end]->full += 1;
				printf("++L%c-%s ", ag.rooms[start]->room[j]->ant, ag.rooms[start]->room[j]->name);
			}
			j++;
		}
	
		k = 0;
        test = 0;
		while (ag.rooms[k])
		{
			if (ag.rooms[k]->full != 0 && ag.rooms[k]->end == 0 && ag.rooms[k]->start == 0)
			{
				j = 0;
				while (ag.rooms[k]->room[j])
				{
					if (ag.rooms[k]->room[j]->full == 0 && ag.rooms[k]->room[j]->start == 0 && 
							ft_strequ(ag.rooms[k]->room[j]->flag, ag.rooms[k]->name) == 0)
					{
						if (ft_strequ(ag.rooms[k]->room[j]->name, ag.rooms[end]->name))
                        {
							ag.rooms[k]->room[j]->full += 1;
						}
                        else
						    ag.rooms[k]->room[j]->full = 1;
						ag.rooms[k]->room[j]->ant = ag.rooms[k]->ant;
						ag.rooms[k]->full = 0;
                        ag.rooms[k]->flag = ft_strdup(ag.rooms[k]->room[j]->name);
						printf(">>>>L%c-%s ", ag.rooms[k]->room[j]->ant, ag.rooms[k]->room[j]->name);
                        test = 1;
						break ;
					}
					else if (ft_strequ(ag.rooms[k]->room[j]->name, ag.rooms[end]->name))
					{
						ag.rooms[k]->full = 0;
						ag.rooms[end]->full += 1;
                        ag.rooms[k]->room[j]->ant = ag.rooms[k]->ant;
						printf("<<<L%c-%s ", ag.rooms[k]->room[j]->ant, ag.rooms[k]->room[j]->name);
                        test = 1;
						break ;
					}
					j++;
				}
			}
            if (test == 1)
                break;
			k++;
		}
		printf("\n----\n");
*//*		else 
		{
			while (ag.rooms[k].name != ag.rooms[start].room[j].name)
			{
				k++;
			}

		}
*/ //	}
/*	printf("name = %s full = %d\n", ag.rooms[end]->name, ag.rooms[end]->full);
	printf("name = %s full = %d\n", ag.rooms[start]->name, ag.rooms[start]->full);
*/	
	return (0);
}
