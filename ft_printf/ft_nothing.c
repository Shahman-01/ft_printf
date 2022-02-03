/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nothing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:51:44 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:51:46 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_nothing(t_flags flag, char ch)
{
	if (flag.minus)
	{
		flag.length += write(1, &ch, 1);
		while (flag.width > 1)
		{
			if (flag.zero == 1 && flag.dot == -1 && !flag.minus)
				flag.length += write(1, "0", 1);
			else
				flag.length += write(1, " ", 1);
			flag.width--;
		}
	}
	else
	{
		while (flag.width > 1)
		{
			if (flag.zero == 1 && flag.dot == -1 && !flag.minus)
				flag.length += write(1, "0", 1);
			else
				flag.length += write(1, " ", 1);
			flag.width--;
		}
		flag.length += write(1, &ch, 1);
	}
	return (flag);
}
