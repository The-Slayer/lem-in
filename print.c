/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstander <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 10:22:49 by hstander          #+#    #+#             */
/*   Updated: 2017/07/31 13:06:16 by hstander         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	main(int ac, char **av)
{
	int fd;
	char *line;

	line = NULL;
	if (ac !=  2)
		exit (0);
	else
	{
		fd = open(av[1], O_RDONLY);
		while (get_next_line(fd, &line) != 0)
		{
			ft_putstr(line);
			ft_putchar('\n');
			if (line != NULL)
				free(line);
		}
		if (line != NULL)
			free(line);
	}
	return (0);
}
