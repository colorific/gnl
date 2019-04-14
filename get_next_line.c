/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:39:27 by forange-          #+#    #+#             */
/*   Updated: 2019/04/14 13:38:18 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
char *ft_get_line()
{

}
*/
int get_next_line(const int fd, char **line)
{
	static t_node *fd_ar[MAX_FD];
	char *res;

	if (line && *line)
	{
		free(*line);
		*line = NULL;
	}
	if ((fd == 0 || fd > 2) && fd < MAX_FD)
	{
		;
	}
	else
		return (-1);
	return (0);
}
