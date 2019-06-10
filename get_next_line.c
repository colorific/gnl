/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:19 by kirill            #+#    #+#             */
/*   Updated: 2019/06/10 17:33:11 by forange-         ###   ########.fr       */
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

/* тут теряется содержимое content */

void *ft_chrealloc(t_node *ptr, size_t size)
{
	unsigned char *res;

	res = (unsigned char*)malloc(size);
	res = ft_memcpy(res, ptr->content, ptr->content_size);
	return (res);
}

int ft_check(t_node *node, char **line)
{
	if (!(node->ch = ft_memchr(node->content, EOL, node->content_size)))
		node->content = (unsigned char*)ft_chrealloc(node, node->content_size + BUFF_SIZE);
	else
	{
		*line = (char*)malloc(node->ch - node->content);
		*line = ft_memcpy(*line, node->content, node->ch - node->content);
		return (1);
	}
	return (0);
}

int ft_readline(int fd, t_node *arr, char **line)
{
	int bytes_read;

	if (!(arr)[fd].ch)
		ft_check(&(arr)[fd], line);
	while (!((bytes_read = read(fd, &(arr)[fd].content + \
			(arr)[fd].content_size, BUFF_SIZE)) % BUFF_SIZE) && bytes_read)
	{
		(arr)[fd].content_size += bytes_read;
		if (ft_check(&(arr)[fd], line))
			return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
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
	if (!ft_readline(fd, fd_ar, line) && !(fd_ar[0].isany))
	{
		free(fd_ar);
		fd_ar = NULL;
	}
	return (fd_ar ? (*line ? 1 : 0) : 0);
}
