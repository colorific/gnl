/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:21:07 by kirill            #+#    #+#             */
/*   Updated: 2018/12/20 19:55:27 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strparse(const char *s, char c, size_t *words)
{
	size_t len;

	*words = 0;
	len = 0;
	while (*s++)
	{
		if (*(s - 1) != c && (*s == c || !*s))
			(*words)++;
		len++;
	}
	return (len);
}
