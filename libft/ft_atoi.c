/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:01:43 by kirill            #+#    #+#             */
/*   Updated: 2018/12/25 00:26:06 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*ft_check_pre(const char *po, int *sign)
{
	if (*po == '-')
	{
		*sign = -1;
		po++;
	}
	else if (*po == '+')
		po++;
	while (*po == '0')
		po++;
	return (po);
}

int					ft_atoi(const char *str)
{
	long int		test;
	long int		res;
	int				sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	str = ft_check_pre(str, &sign);
	while (ft_isdigit(*str))
	{
		test = res;
		res = res * 10 + (*str - 48);
		if (test > (res / 10))
			return (sign > 0 ? -1 : 0);
		str++;
	}
	return (res * sign);
}
