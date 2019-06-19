/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:38:18 by forange-          #+#    #+#             */
/*   Updated: 2019/06/19 21:21:50 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFF_SIZE 3
# define MAX_FD 4865 /* ulimit -n */
# define EOL 0x0A

typedef struct		s_node
{
	unsigned char	*content;
	unsigned char	*ch;
	int				isany;
	int				arsize;
	int				content_size;
}					t_node;

int	get_next_line(const int fd, char **line);

#endif
