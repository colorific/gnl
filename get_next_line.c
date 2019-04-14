/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:39:27 by forange-          #+#    #+#             */
/*   Updated: 2019/04/14 20:40:49 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(const int fd, char **line)
{
	static t_node	**fd_ar;
	t_node			**temp;
//	char			*res;
	int				len;

	len = MAX_FD;
	if (!line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!fd_ar || fd >= len)
	{
		temp = (fd >= len ? fd_ar : NULL);
		if (!(fd_ar = (t_node**)malloc(sizeof(t_node*) * \
			(fd >= len ? fd + 1 : len))))
			return (-1);
		else
			ft_bzero(fd_ar, (fd >= len ? fd + 1 : len));
		if (temp)
		{
			ft_memcpy(fd_ar, temp, sizeof(t_node**) * len);
			ft_memdel((void**)&temp);
		}
	}
	if (*line)
		ft_memdel((void**)line);
	if (fd == 0 || fd > 2)
	{
		;
	}
	else
		return (-1);
	return (0);
}
