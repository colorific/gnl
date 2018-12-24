/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 23:39:45 by kirill            #+#    #+#             */
/*   Updated: 2018/12/15 18:53:55 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*ndest;
	const char	*nsrc;

	ndest = (char *)dst;
	nsrc = (const char *)src;
	if (dst != src)
	{
		while (n--)
			*ndest++ = *nsrc++;
	}
	return (dst);
}
