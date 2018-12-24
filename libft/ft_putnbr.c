/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 20:36:12 by forange-          #+#    #+#             */
/*   Updated: 2018/12/20 20:51:15 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int i;

	i = (long int)n;
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (i > 9)
		ft_putnbr(i / 10);
	else
	{
		ft_putchar(i + '0');
		return ;
	}
	ft_putchar((i % 10) + '0');
}
