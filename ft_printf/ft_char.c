/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:51:13 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:51:19 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_char(t_flags flag, char ch)
{
	if (flag.minus)
	{
		flag.length += write(1, &ch, 1);
		while (flag.width > 1)
		{
			flag.length += write(1, " ", 1);
			flag.width--;
		}
	}
	else
	{
		while (flag.width > 1)
		{
			flag.length += write(1, " ", 1);
			flag.width--;
		}
		flag.length += write(1, &ch, 1);
	}
	return (flag);
}
