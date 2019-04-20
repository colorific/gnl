/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:38:18 by forange-          #+#    #+#             */
/*   Updated: 2019/04/19 19:11:30 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 8
# define MAX_FD 4865 /* ulimit -n */
# define EOL 0x0A

typedef struct		s_node
{
	unsigned char	*content;
	size_t			content_size;
	unsigned char	*ch;
	void			*isany;
	int				arsize;
}					t_node;

int	get_next_line(const int fd, char **line);

#endif
