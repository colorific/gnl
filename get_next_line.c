/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:39:27 by forange-          #+#    #+#             */
/*   Updated: 2019/04/03 21:48:50 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_line()
{

}

int	get_next_line(const int fd, char **line)
{
	static t_node fd_ar[MAX_FD];
	char *res;

	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	if ((fd == 0 || fd > 2) && fd < MAX_FD && line)
	{
		if (fd_ar[fd].flag == EMPTY | EOF)
		{
			while ((fd_ar[fd].size = read(fd, fd_ar[fd].str, BUFF_SIZE) > 0)
			{

			}
		}
	}
	else
		return (-1);
}
