/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:02:07 by kirill            #+#    #+#             */
/*   Updated: 2018/12/15 18:56:42 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char				*d;
	const unsigned char	*s;
	unsigned char		f;

	d = (char *)dst;
	s = (const unsigned char *)src;
	f = (unsigned char)c;
	while (n && *s != f)
	{
		*d++ = *s++;
		--n;
	}
	if (!n)
		return (NULL);
	else
	{
		*d++ = *s;
		return (d);
	}
}
