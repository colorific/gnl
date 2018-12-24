/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 23:54:29 by forange-          #+#    #+#             */
/*   Updated: 2018/12/21 01:42:23 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *res;
	t_list *next;

	if (alst)
	{
		res = *alst;
		while (res->next)
		{
			next = res->next;
			del(res->content, res->content_size);
			free(res);
			res = next;
		}
		del(res->content, res->content_size);
		free(res);
		*alst = NULL;
	}
}
