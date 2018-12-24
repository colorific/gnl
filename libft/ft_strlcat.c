/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:22:15 by forange-          #+#    #+#             */
/*   Updated: 2018/12/17 19:10:50 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lend;
	size_t lens;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	if (size > lend + 1)
	{
		if (size - lend - 1 >= lens)
			ft_memcpy(dst + lend, src, lens + 1);
		else
		{
			ft_memcpy(dst + lend, src, size - lend - 1);
			*(dst + size - 1) = '\0';
		}
	}
	return (lend > size ? lens + size : lens + lend);
}
