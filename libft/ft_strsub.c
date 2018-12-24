/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirill <kirill@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:13:11 by kirill            #+#    #+#             */
/*   Updated: 2018/12/18 16:03:11 by kirill           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *res;

	res = NULL;
	if (s)
	{
		if ((res = (char *)malloc(len + 1)))
		{
			res = ft_memcpy(res, &s[start], len);
			res[len] = '\0';
		}
	}
	return (res);
}
