/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helps_funk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:53:16 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:53:17 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(int len)
{
	t_flags		flags;

	flags.length = len;
	flags.space = 0;
	flags.base = 10;
	flags.u_or_l = 0;
	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.i = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

int	ft_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

t_flags	ft_putstr(char *str, int len, t_flags flag)
{
	while (*str && len > 0)
	{
		flag.length += write(1, &*str, 1);
		str++;
		len--;
	}
	return (flag);
}
