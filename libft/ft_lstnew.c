/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 23:09:27 by forange-          #+#    #+#             */
/*   Updated: 2018/12/20 23:37:35 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *res;

	if ((res = (t_list*)malloc(sizeof(t_list))))
	{
		if (!content || !content_size)
		{
			res->content = NULL;
			res->content_size = 0;
		}
		else
		{
			if ((res->content = malloc(content_size)))
			{
				res->content = ft_memcpy(res->content, content, content_size);
				res->content_size = content_size;
			}
			else
				return (NULL);
		}
		res->next = NULL;
	}
	return (res);
}
