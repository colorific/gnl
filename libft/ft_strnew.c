/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:06:25 by forange-          #+#    #+#             */
/*   Updated: 2018/12/25 00:40:36 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	if (!(size + 1))
		return (NULL);
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	ft_bzero(res, size + 1);
	return (res);
}
