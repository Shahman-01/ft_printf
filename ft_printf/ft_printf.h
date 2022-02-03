/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppeapod <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 18:52:14 by ppeapod           #+#    #+#             */
/*   Updated: 2021/07/03 18:52:16 by ppeapod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	int				length;
	int				space;
	int				base;
	int				u_or_l;
	int				i;
	int				width;
	int				minus;
	int				zero;
	int				dot;
	int				star;
}				t_flags;

int			ft_printf(const char *fmt, ...);
int			ft_len(const char *s);
char		*ft_itoa_p(unsigned long nbr, t_flags flag, int base, int u_or_l);
t_flags		ft_str(t_flags flag, char *str);
t_flags		ft_putstr(char *str, int len, t_flags flag);
t_flags		ft_char(t_flags flag, char ch);
t_flags		ft_dec(t_flags flag, long nbr);
t_flags		ft_nothing(t_flags flag, char ch);
t_flags		ft_x(t_flags flag, unsigned int nbr);
t_flags		ft_X(t_flags flag, unsigned int nbr);
t_flags		ft_u(t_flags flag, unsigned int nbr);
t_flags		ft_p(t_flags flag, const long long nbr);
t_flags		ft_three_if(t_flags flag, int i, char *fmt);
t_flags		ft_star_foo(t_flags flag, int num, char ch);
t_flags		ft_if_star(t_flags flag, int i, char *fmt, va_list args);
t_flags		ft_if_dot(t_flags flag, int i, char *fmt, va_list args);
t_flags		ft_init_flags(int len);
t_flags		ft_flags_change_dop(t_flags flag, int len);
t_flags		ft_flags_change(t_flags flag, char *str, int len);

#endif
