/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 22:10:09 by kirill            #+#    #+#             */
/*   Updated: 2018/12/29 22:43:12 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static t_list pre;
	static t_list post;

	if (fd > 0 && line)
	{
		 (read(fd, pre.content, BUFF_SIZE))
		{

		}
	}
}
