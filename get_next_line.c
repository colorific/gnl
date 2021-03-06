/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:19 by kirill            #+#    #+#             */
/*   Updated: 2019/06/29 20:34:22 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			*ft_myrealloc(t_node *ptr, size_t size, char type)
{
	void		*temp;

	temp = (t_node *)ft_memalloc(size);
	if (!temp)
		return (NULL);
	if (type != 'c')
	{
		temp = ft_memcpy(temp, (type == 'm' ? (void*)ptr : (void*)ptr->content),\
		type == 'm' ? ptr[0].arsize * sizeof(t_node) : ptr->content_size);
		if (ptr->content || type == 'm')
		{
			free(type == 'm' ? (void *)ptr : (void*)ptr->content);
			if (type == 'n')
				ptr->content = NULL;
		}
	}
	return (temp);
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
		if (!(node->content = (unsigned char*)ft_myrealloc(node, \
		node->content_size + BUFF_SIZE, 'n')))
			return (-1);
	}
	else
	{
		*line = ft_writeline(node);
		return (*line ? 1 : -1);
	}
	return (0);
}

int					ft_readline(int fd, t_node *arr, char **line)
{
	int				bytes_read;

	if ((bytes_read = ft_check(&(arr)[fd], line)))
		return (bytes_read);
	while ((bytes_read = read(fd, (void *)\
	(&(arr)[fd].content[arr[fd].content_size]), BUFF_SIZE)))
	{
		(arr)[fd].content_size += bytes_read;
		if ((bytes_read = ft_check(&(arr)[fd], line)))
			return (bytes_read);
	}
	if (!arr[fd].content_size)
		ft_memdel((void**)&arr[fd].content);
	else
	{
		*line = ft_writeline(&(arr)[fd]);
		return (*line ? 1 : -1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_node	*fd_ar;
	int				out;

	if (!line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!fd_ar || fd >= fd_ar[0].arsize)
	{
		if (!(fd_ar = ft_myrealloc(fd_ar, (fd >= MAX_FD ? fd + 1 : MAX_FD) *\
		sizeof(t_node), fd_ar ? 'm' : 'c')))
			return (-1);
		fd_ar[0].arsize = (fd >= MAX_FD ? fd + 1 : MAX_FD);
	}
	if (!(out = ft_readline(fd, fd_ar, line)))
	{
		while (!fd_ar[out].content_size && out++ < fd_ar[0].arsize)
		{
			if (out == fd_ar[0].arsize)
			{
				free(fd_ar);
				fd_ar = NULL;
				break;
			}
		}
	}
	return (out > 1 ? 0 : out);
}
