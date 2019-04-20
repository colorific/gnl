/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:19 by kirill            #+#    #+#             */
/*   Updated: 2019/04/19 19:08:56 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node *ft_realloc(t_node *ptr, size_t size)
{
	t_node *temp;

	if ((temp = (t_node *)ft_memalloc(size * sizeof(t_node))) != 0)
	{
		temp = ft_memcpy(temp, ptr, (ptr->arsize));
		temp[0].arsize = size;
		ft_memdel((void **)ptr);
	}
	return (temp);
}

int ft_readline(int fd, t_node **arr, char **line)
{
	if (!(*arr)[fd].content)
	{
		if (!((*arr)[fd].content = malloc(BUFF_SIZE)))
			return (-1);
		while (!(((*arr)[fd].content_size += read(fd, &(*arr)[fd].content, \
				BUFF_SIZE)) % BUFF_SIZE))
		{
			if (((*arr)[fd].ch = ft_memchr(&(*arr)[fd].content, EOL, (*arr)[fd].content_size)))
			{
				*line = (char*)malloc((unsigned char*)(*arr)[fd].ch - (unsigned char*)&(*arr)[fd].content);
				ft_memccpy(*line, &(*arr)[fd].content, EOL, \
						(*arr)[fd].content_size);
			}/*
			else
			{
				temp = (char*)malloc()
			}
*/
		}
	}
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static t_node *fd_ar;

	if (!line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!fd_ar)
	{
		if (!(fd_ar = (t_node *)ft_memalloc(sizeof(t_node) * \
			(fd >= MAX_FD ? fd + 1 : MAX_FD))))
			return (-1);
		fd_ar[0].arsize = (fd >= MAX_FD ? fd + 1 : MAX_FD);
	}
	if (fd >= fd_ar[0].arsize)
	{
		if (!(fd_ar = ft_realloc(fd_ar, fd + 1)))
			return (-1);
	}
	if (!ft_readline(fd, &fd_ar, line) && !(fd_ar[0].isany))
	{
		free(fd_ar);
		fd_ar = NULL;
	}
	return (fd_ar ? (*line ? 1 : 0) : 0);
}
