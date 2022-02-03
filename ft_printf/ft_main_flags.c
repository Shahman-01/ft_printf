/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 19:30:43 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 19:30:45 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_three_if(t_flags flag, int i, char *fmt)
{
	flag.i = i;
	if (fmt[flag.i] == ' ')
	{
		ft_nothing(flag, fmt[flag.i]);
		flag.i++;
	}
	while (fmt[flag.i] == '-')
	{
		flag.minus = 1;
		flag.i++;
	}
	if (fmt[flag.i] == '0')
	{
		flag.zero = 1;
		flag.i++;
	}
	return (flag);
}

t_flags	ft_star_foo(t_flags flag, int num, char ch)
{
	int	star;

	star = num;
	if (ch == 'w')
	{
		if (star < 0)
		{
			flag.minus = 1;
			star *= -1;
		}
		while (star > 0)
		{	
			flag.width++;
			star--;
		}
	}
	else if (ch == 'd')
	{
		if (star < 0)
			flag.dot = -1;
		while (star-- > 0)
			flag.dot++;
	}
	flag.star = 1;
	return (flag);
}

t_flags	ft_if_star(t_flags flag, int i, char *fmt, va_list args)
{
	flag.i = i;
	if (fmt[flag.i] == '*')
	{
		flag = ft_star_foo(flag, va_arg(args, int), 'w');
		flag.i++;
	}
	else
	{
		while (fmt[flag.i] >= '0' && fmt[flag.i] <= '9')
		{
			flag.width = flag.width * 10 + fmt[flag.i] - '0';
			flag.i++;
		}
	}
	return (flag);
}

t_flags	ft_if_dot(t_flags flag, int i, char *fmt, va_list args)
{
	flag.i = i;
	if (fmt[flag.i] == '.')
	{
		flag.dot = 0;
		flag.i++;
		if (fmt[flag.i] == '-')
			return (flag);
		if (fmt[flag.i] == '*')
		{
			flag = ft_star_foo(flag, va_arg(args, int), 'd');
			flag.i++;
		}
		else
		{
			while (fmt[flag.i] >= '0' && fmt[flag.i] <= '9')
			{
				flag.dot = flag.dot * 10 + fmt[flag.i] - '0';
				flag.i++;
			}
		}
	}
	return (flag);
}
