/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:29:11 by kirill            #+#    #+#             */
/*   Updated: 2018/12/16 17:29:19 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	size_t		len;
	const char	*ptr;

	len = ft_strlen(s);
	ptr = s + len;
	while (*ptr != (char)c)
	{
		ptr--;
		if (ptr < s)
			return (NULL);
	}
	return ((char *)ptr);
}
