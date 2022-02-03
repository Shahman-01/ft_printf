/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:51:34 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:51:36 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*ft_itoa_dop(unsigned long nbr, t_flags flag, int l, char *s)
{
	while (l > 0)
	{
		s[l - 1] = nbr % flag.base;
		if (flag.u_or_l == 0)
		{
			if (nbr % flag.base > 9)
				s[l - 1] += 'a' - 10;
			else
				s[l - 1] += '0';
		}
		else if (flag.u_or_l == 1)
		{
			if (nbr % flag.base > 9)
				s[l - 1] += 'A' - 10;
			else
				s[l - 1] += '0';
		}
		nbr /= flag.base;
		l--;
	}
	return (s);
}

char	*ft_itoa_p(unsigned long nbr, t_flags flag, int base, int u_or_l)
{
	unsigned long	temp_nbr;
	int				len;
	char			*str;

	flag.base = base;
	flag.u_or_l = u_or_l;
	temp_nbr = nbr;
	str = NULL;
	len = 0;
	if (nbr == 0)
		len++;
	while (temp_nbr > 0)
	{
		temp_nbr /= base;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	return (ft_itoa_dop(nbr, flag, len, str));
}
