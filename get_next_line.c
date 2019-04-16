/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:13:19 by kirill            #+#    #+#             */
/*   Updated: 2019/04/16 16:40:16 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list *ft_realloc(t_list *ptr, size_t size)
{
	t_list *temp;

	temp = (t_list *)ft_memalloc(size * sizeof(t_list));
	temp = ft_memcpy(temp, ptr, (ptr->next - ptr));
	ft_memdel((void **)ptr);
	return (temp);
}
/* В указатель next лежит:
	1) адрес последнего элемента массива
	2) NULL если по данному fd достигнут EOF
 */
int ft_readline(int fd, t_list **arr, char **line)
{
	if (arr[fd]->next == NULL)
		return (0);
	(void)line;
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
