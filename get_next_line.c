/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:19 by kirill            #+#    #+#             */
/*   Updated: 2019/06/28 22:57:35 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node				*ft_realloc(t_node *ptr, size_t size)
{
	t_node			*temp;

	temp = NULL;
	if ((temp = (t_node *)ft_memalloc(size * sizeof(t_node))) != 0)
	{
		temp = ft_memcpy(temp, ptr, ptr[0].arsize);
		temp[0].arsize = size;
		ft_memdel((void **)ptr);
	}
	return (temp);
}

void				*ft_chrealloc(t_node *ptr, size_t size)
{
	unsigned char	*res;

	res = (unsigned char*)malloc(size);
	if (!res)
		return (NULL);
	res = (unsigned char*)ft_memcpy(res, ptr->content, ptr->content_size);
	if (ptr->content)
	{
		free((void*)ptr->content);
		ptr->content = NULL;
	}
	return (res);
}

char				*ft_writeline(t_node *node)
{
	char			*out;
	unsigned char	*new_content;

	if (!(out = (char*)ft_memalloc((node->ch ? node->ch - node->content :\
									node->content_size) + 1)))
		return (out);
	out = (char*)ft_memcpy(out, node->content,\
	(node->ch ? node->ch - node->content : node->content_size));
	if (node->ch)
	{
		new_content = (unsigned char*)ft_memalloc(&node->content\
		[node->content_size - 1] - node->ch + BUFF_SIZE);
		new_content = ft_memcpy(new_content, node->ch + 1,\
		&node->content[node->content_size - 1] - node->ch);
		node->content_size = &node->content[node->content_size - 1] - node->ch;
	}
	else
		node->content_size = 0;
	free((void*)node->content);
	node->content = node->ch ? new_content : NULL;
	return (out);
}

int					ft_check(t_node *node, char **line)
{
	if (!(node->ch = (unsigned char*)ft_memchr(node->content, EOL,\
			node->content_size)))
	{
		if (!(node->content = (unsigned char*)ft_chrealloc(node, \
		node->content_size + BUFF_SIZE)))
			return (-1);
	}
	else
	{
		*line = ft_writeline(node);
		return (1);
	}
	return (0);
}

int					ft_readline(int fd, t_node *arr, char **line)
{
	int				bytes_read;

	if (ft_check(&(arr)[fd], line))
		return (1);
	while ((bytes_read = read(fd, (void *)\
	(&(arr)[fd].content[arr[fd].content_size]), BUFF_SIZE)))
	{
		(arr)[fd].content_size += bytes_read;
		if (ft_check(&(arr)[fd], line))
			return (1);
	}
	if (!arr[fd].content_size)
		ft_memdel((void**)&arr[fd].content);
	else
	{
		*line = ft_writeline(&(arr)[fd]);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_node	*fd_ar;
	int				out;

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
	if (!(out = ft_readline(fd, fd_ar, line)))
	{
		;
//		free(fd_ar);
//		fd_ar = NULL;
	}
	return (out ? 1 : 0);
}
