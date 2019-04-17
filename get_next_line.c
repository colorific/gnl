/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:19 by kirill            #+#    #+#             */
/*   Updated: 2019/04/17 10:19:33 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list *ft_realloc(t_list *ptr, size_t size)
{
	t_list *temp;

	temp = (t_list *)ft_memalloc(size * sizeof(t_list));
	temp = ft_memcpy(temp, ptr, (ptr->next - ptr));
	temp[0].next = temp + size - 1;
	ft_memdel((void **)ptr);
	return (temp);
}

/*
**	В указатель next лежит:
**	1) адрес последнего элемента массива
**	2) NULL если по данному fd достигнут EOF
*/
int ft_readline(int fd, t_list **arr, char **line)
{
	//unsigned char* temp;

	if (!(*arr)[fd].content)
	{
		if (!((*arr)[fd].content = malloc(BUFF_SIZE)))
			return (-1);
		while(((*arr)[fd].content_size = \
			read(fd, &(*arr)[fd].content, BUFF_SIZE)) > 0)
		{
			*line = (char*)ft_memalloc((*arr)[fd].content_size);
			ft_memccpy(*line, &(*arr)[fd].content, EOL, \
				(*arr)[fd].content_size);
		}
	}
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static t_list *fd_ar;

	if (!line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!fd_ar)
	{
		if (!(fd_ar = (t_list *)ft_memalloc(sizeof(t_list) * MAX_FD)))
			return (-1);
		fd_ar[0].next = fd_ar + MAX_FD - 1;
	}
	if (fd >= fd_ar[0].next - fd_ar)
		fd_ar = ft_realloc(fd_ar, fd + 1);
	if (*line)
		ft_memdel((void **)line);
	return (fd_ar ? ft_readline(fd, &fd_ar, line) : -1);
}
