/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:51:25 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:51:27 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_flags	ft_pechat(char *str, int num, t_flags flag)
{
	if (flag.dot >= -1 && num < 0 && !flag.space)
		flag.length += write(1, "-", 1);
	if (flag.dot >= 0)
	{
		while (flag.dot > ft_len(str))
		{
			flag.length += write(1, "0", 1);
			flag.dot--;
			flag.width--;
		}
	}
	flag = ft_putstr(str, ft_len(str), flag);
	return (flag);
}

static	t_flags 	ft_flag_d(char *str, int num, t_flags flag)
{
	if (flag.minus == 1)
		flag = ft_pechat(str, num, flag);
	if (flag.dot >= 0 && flag.dot < ft_len(str))
		flag.dot = ft_len(str);
	if (flag.dot >= 0)
	{
		flag.width -= flag.dot;
		flag = ft_flags_change_dop(flag, 0);
	}
	else
		flag = ft_flags_change_dop(flag, ft_len(str));
	if (flag.minus == 0)
		flag = ft_pechat(str, num, flag);
	return (flag);
}

t_flags	ft_dec(t_flags flag, long nbr)
{
	int		num;
	char	*str;

	num = nbr;
	if (flag.dot == 0 && nbr == 0)
	{
		ft_flags_change_dop(flag, 0);
		return (flag);
	}
	if (nbr < 0 && (flag.dot >= -1 || flag.zero == 1))
	{
		if (flag.dot < -1 && flag.zero == 1)
			flag.length += write(1, "-", 1);
		if (flag.zero && flag.dot == -1)
		{
			flag.length += write(1, "-", 1);
			flag.space = 1;
		}
		nbr *= -1;
		flag.width--;
	}
	str = ft_itoa_p(nbr, flag, 10, 0);
	flag = ft_flag_d(str, num, flag);
	free(str);
	return (flag);
}
