/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_change.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:30:23 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 19:30:25 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_flags_change_dop(t_flags flag, int len)
{
	while (flag.width > len)
	{
		if (flag.zero == 1 && flag.dot == -1 && !flag.minus)
			flag.length += write(1, "0", 1);
		else
			flag.length += write(1, " ", 1);
		flag.width--;
	}
	return (flag);
}

t_flags	ft_flags_change(t_flags flag, char *str, int len)
{
	if (flag.minus)
	{
		while (len > ft_len(str))
		{
			flag.length += write(1, "0", 1);
			len--;
			flag.width--;
		}	
		flag = ft_putstr(str, ft_len(str), flag);
		free(str);
	}
	flag = ft_flags_change_dop(flag, len);
	while (len > ft_len(str) && !flag.minus)
	{
		flag.length += write(1, "0", 1);
		len--;
	}
	if (!flag.minus)
	{
		flag = ft_putstr(str, ft_len(str), flag);
		free(str);
	}
	return (flag);
}
