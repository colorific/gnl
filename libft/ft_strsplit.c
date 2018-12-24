/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:10:59 by kirill            #+#    #+#             */
/*   Updated: 2018/12/21 03:59:26 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_freeall(char **ptr, size_t i)
{
	while (i-- != 0)
		ft_memdel((void **)&ptr[i]);
}

static void	ft_justdoit(char **ptr, char const *s, char c, size_t tlen)
{
	char	*cptr;
	size_t	i;
	size_t	jmp;

	i = 0;
	while (*s)
	{
		while (*s == c)
		{
			tlen--;
			s++;
		}
		if (!*s)
			break ;
		cptr = (char *)ft_memchr(s, c, tlen);
		jmp = cptr ? (size_t)(cptr - s) : tlen;
		if (!(ptr[i++] = ft_strsub(s, 0, jmp)))
		{
			ft_freeall(&(*ptr), --i);
			return ;
		}
		s += jmp;
		tlen -= jmp;
	}
	ptr[i] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	tlen;
	size_t	words;
	char	**ptr;

	ptr = NULL;
	if (s)
	{
		tlen = ft_strparse(s, c, &words);
		if ((ptr = (char**)malloc(sizeof(char*) * (words + 1))))
			ft_justdoit(&(*ptr), s, c, tlen);
		if (ptr && !*ptr)
			free(ptr);
	}
	return (ptr ? ptr : NULL);
}
