/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 22:14:32 by forange-          #+#    #+#             */
/*   Updated: 2018/12/16 17:29:05 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	size;
	char	*end;

	size = ft_strlen(s);
	end = (char *)s + size;
	if (!size)
	{
		end = ((char)c == 0 ? (char *)s : NULL);
		return (end);
	}
	else
	{
		while (s <= end)
		{
			if (*s == (char)c)
				return ((char *)s);
			s++;
		}
		return (NULL);
	}
}
