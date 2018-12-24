/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:36:54 by forange-          #+#    #+#             */
/*   Updated: 2018/12/16 19:44:35 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > n)
	{
		ft_memcpy(s1 + len1, s2, n);
		*(s1 + len1 + n) = '\0';
	}
	else
		ft_memcpy(s1 + len1, s2, len2 + 1);
	return (s1);
}
