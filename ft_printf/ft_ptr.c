/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:52:23 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:52:26 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_flags	ft_ft_p_dop(t_flags flag)
{
	flag.length += write(1, "0", 1);
	flag.length += write(1, "x", 1);
	return (flag);
}

t_flags	ft_p(t_flags flag, const long long nbr)
{
	char			*str;
	int				len;
	unsigned long	p_nbr;

	p_nbr = nbr;
	str = ft_itoa_p(p_nbr, flag, 16, 0);
	len = ft_len(str) + 2;
	if (flag.dot != -1 && flag.dot > len)
		len = flag.dot;
	if (flag.minus)
	{
		flag = ft_ft_p_dop(flag);
		flag = ft_putstr(str, ft_len(str), flag);
		free(str);
	}
	while (flag.width-- > len)
		flag.length += write(1, " ", 1);
	if (!flag.minus)
	{
		flag = ft_ft_p_dop(flag);
		flag = ft_putstr(str, ft_len(str), flag);
		free(str);
	}
	return (flag);
}
