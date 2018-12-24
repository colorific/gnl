/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 02:08:57 by forange-          #+#    #+#             */
/*   Updated: 2018/12/21 03:24:18 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstfree(void *m, size_t n)
{
	free(((t_list*)m)->content);
	free(m);
	n = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*next;
	t_list	*prev;

	res = NULL;
	if (lst && f)
	{
		if (!(res = (t_list*)malloc(sizeof(t_list))))
			return (res);
		res = f(lst);
		prev = res;
		while ((lst = lst->next))
		{
			if (!(next = (t_list*)malloc(sizeof(t_list))))
			{
				ft_lstdel(&res, ft_lstfree);
				return (next);
			}
			next = f(lst);
			prev->next = next;
			prev = next;
		}
	}
	return (res);
}
