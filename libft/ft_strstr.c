/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 18:33:19 by forange-          #+#    #+#             */
/*   Updated: 2018/12/10 19:24:13 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *res;
	char *mem;

	if (!(*needle))
		return ((char*)haystack);
	else
	{
		while (*haystack)
		{
			mem = (char*)needle;
			if (*haystack == *mem)
			{
				res = (char *)haystack;
				while (*haystack++ == *mem++)
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
