/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:52:33 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:52:35 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_flags	ft_ft_str_dop(t_flags flag, int len, char *str)
{
	if (flag.minus)
	{
		flag = ft_putstr(str, len, flag);
		while (flag.width-- > len)
			flag.length += write(1, " ", 1);
	}
	else
	{
		while (flag.width-- > len)
			flag.length += write(1, " ", 1);
		flag = ft_putstr(str, len, flag);
	}
	return (flag);
}

t_flags	ft_str(t_flags flag, char *str)
{
	int	len;

	if (!str)
		str = "(null)";
	len = ft_len(str);
	if (flag.dot != -1 && flag.dot < len)
		len = flag.dot;
	flag = ft_ft_str_dop(flag, len, str);
	return (flag);
}
