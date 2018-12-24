/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 23:13:47 by kirill            #+#    #+#             */
/*   Updated: 2018/12/17 20:08:51 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *src;

	if (!n)
		return (NULL);
	src = (const unsigned char *)s;
	while ((*src != (unsigned char)c) && --n)
		src++;
	return (n ? (void *)src : NULL);
}
