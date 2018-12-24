/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:02:53 by kirill            #+#    #+#             */
/*   Updated: 2018/12/20 19:55:14 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	len;

	res = NULL;
	if (s && f)
	{
		len = ft_strlen(s);
		if ((res = (char *)malloc(len + 1)))
		{
			res[len] = s[len];
			while (len--)
				res[len] = f(len, s[len]);
		}
	}
	return (res);
}
