/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:52:05 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:52:07 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static	t_flags	ft_what_type(t_flags flag, char ch, va_list args)
{
	if (ch == 's')
		flag = ft_str(flag, va_arg(args, char *));
	else if (ch == 'x')
		flag = ft_x(flag, va_arg(args, unsigned long long));
	else if (ch == 'X')
		flag = ft_X(flag, va_arg(args, unsigned long long));
	else if (ch == 'c')
		flag = ft_char(flag, va_arg(args, int));
	else if (ch == 'd' || ch == 'i')
		flag = ft_dec(flag, va_arg(args, int));
	else if (ch == 'u')
		flag = ft_u(flag, va_arg(args, unsigned long long));
	else if (ch == 'p')
		flag = ft_p(flag, va_arg(args, long long));
	else if (ch == '%')
		flag = ft_nothing(flag, ch);
	return (flag);
}

static	t_flags	ft_main_foo(t_flags flag, int i, va_list args, char *fmt)
{
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%' && fmt[i] != 0)
		{
			i++;
			flag = ft_init_flags(flag.length);
			flag = ft_three_if(flag, i, fmt);
			i = flag.i;
			flag = ft_if_star(flag, i, fmt, args);
			i = flag.i;
			flag = ft_if_dot(flag, i, fmt, args);
			i = flag.i;
			flag = ft_what_type(flag, fmt[i], args);
		}
		else if (fmt[i] == '\n')
			flag.length += write(1, "\n", 1);
		else
			flag.length += write(1, &fmt[i], 1);
		i++;
	}
	return (flag);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	t_flags	flag;

	i = 0;
	flag.length = 0;
	flag = ft_init_flags(flag.length);
	va_start(args, fmt);
	flag = ft_main_foo(flag, i, args, (char *)fmt);
	va_end(args);
	return (flag.length);
}
