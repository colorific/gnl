/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:27:48 by forange-          #+#    #+#             */
/*   Updated: 2018/12/10 20:58:28 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*res;
	char	*mem;
	size_t	my_size;

	if (!(*needle))
		return ((char*)haystack);
	else
	{
		while (*haystack && len-- >= 1)
		{
			mem = (char*)needle;
			if (*haystack == *mem && (my_size = len + 1))
			{
				res = (char *)haystack;
				while (*haystack++ == *mem++ && my_size-- >= 1)
				{
					if (!(*mem))
						return (res);
				}
				haystack = res;
			}
			haystack++;
		}
		return (NULL);
	}
}
