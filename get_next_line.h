/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:38:18 by forange-          #+#    #+#             */
/*   Updated: 2019/04/03 14:46:30 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 32

typedef struct	s_node
{
	void		*str;
	int			size; 		/* if flag = -1 size of *str; flag = 1 size until \n */
	char		flag; 		/* 0 - no data, 1 - some left and \n included, -1 - some left and no \n */
}				t_node;

int	get_next_line(const int fd, char **line);

#endif
