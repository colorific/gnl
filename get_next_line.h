/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:38:18 by forange-          #+#    #+#             */
/*   Updated: 2019/04/08 18:03:56 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 32
# define EOF 0
# define MAX_FD 4865 /* ulimit -n */

enum state_flags
{
	EMPTY = 0,
	FILLED = 1,
	END = 2
} flags;

typedef struct	s_node
{
	char		str[BUFF_SIZE]; /* if (*str == '\0' && !flag) - new fd, if (!*str && flag == -1) - EOF */
	int			size; 			/* if flag = -1 size of *str; flag = 1 size until \n */
	char		flag; 			/* 0 - no data, 1 - some left and \n included, -1 - EOF */
}				t_node;

int	get_next_line(const int fd, char **line);

#endif
