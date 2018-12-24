/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 21:13:19 by kirill            #+#    #+#             */
/*   Updated: 2018/12/20 19:53:48 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_fillstr(long int n, int len, char *out)
{
	if (n < 0)
	{
		n = -n;
		out[0] = '-';
	}
	if (n > 9)
	{
		out[len] = n % 10 + '0';
		ft_fillstr(n / 10, --len, out);
	}
	else
		out[len] = n % 10 + '0';
}

static size_t	*ft_ssize(long int n, size_t *res)
{
	if (!res)
	{
		if (!(res = (size_t*)ft_memalloc(sizeof(size_t))))
			return (res);
	}
	if (n < 0)
		n = -n;
	if (n > 9)
		res = ft_ssize((n / 10), res);
	++(*res);
	return (res);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		*len;
	long int	p;

	p = (long int)n;
	len = NULL;
	str = NULL;
	if ((len = ft_ssize(p, len)))
	{
		if ((str = (char*)ft_memalloc(sizeof(char) * \
		(p < 0 ? ++*len : *len) + 1)))
			ft_fillstr(p, --*len, str);
	}
	return (str);
}
