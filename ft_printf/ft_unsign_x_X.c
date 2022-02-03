/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign_x_X.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:53:06 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:53:08 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_x(t_flags flag, unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa_p(nbr, flag, 16, 0);
	len = ft_len(str);
	if (nbr == 0 && flag.dot == 0)
	{
		while (flag.width > 0)
		{
			flag.length += write(1, " ", 1);
			flag.width--;
		}
		free (str);
		return (flag);
	}
	if (flag.dot != -1 && flag.dot > len)
		len = flag.dot;
	flag = ft_flags_change(flag, str, len);
	return (flag);
}

t_flags	ft_X(t_flags flag, unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa_p(nbr, flag, 16, 1);
	len = ft_len(str);
	if (nbr == 0 && flag.dot == 0)
	{
		while (flag.width > 0)
		{
			flag.length += write(1, " ", 1);
			flag.width--;
		}
		free (str);
		return (flag);
	}
	if (flag.dot != -1 && flag.dot > len)
		len = flag.dot;
	flag = ft_flags_change(flag, str, len);
	return (flag);
}

t_flags	ft_u(t_flags flag, unsigned int nbr)
{
	char	*str;
	int		len;

	str = ft_itoa_p(nbr, flag, 10, 0);
	len = ft_len(str);
	if (nbr == 0 && flag.dot == 0)
	{
		while (flag.width > 0)
		{
			flag.length += write(1, " ", 1);
			flag.width--;
		}
		free (str);
		return (flag);
	}
	if (flag.dot != -1 && flag.dot > len)
		len = flag.dot;
	flag = ft_flags_change(flag, str, len);
	return (flag);
}
