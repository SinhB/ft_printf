/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:48:20 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/19 15:14:27 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double		ft_round(t_printf *pf, long double nb, int prec)
{
	long double new;
	intmax_t	tmp;
	int			ilast;

	new = (nb - (intmax_t)nb) * 10;
	if (pf->precision == -1)
	{
		tmp = nb * 10;
		return (nb + (tmp % 10 >= 5));
	}
	ilast = 0;
	while (prec-- > 0)
	{
		tmp = (intmax_t)new % 10;
		if (tmp != 9 && tmp != -9)
			pf->last_up = ilast;
		new *= 10.0;
		ilast++;
	}
	tmp = (intmax_t)new % 10;
	pf->extended_prec = (ft_abs(tmp) < 5 && ft_abs(tmp) != 9) ? 0 : 1;
	return (nb);
}

int				ft_putllnbr(t_printf *pf, intmax_t nb)
{
	int			i;

	i = 1;
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
		i += ft_putllnbr(pf, (nb / 10));
	char_padding(pf, (nb % 10 + 48));
	return (i);
}

static void		f_flags_padding(t_printf *pf, long double nb)
{
	if ((nb < 0) || !(1 / nb > 0))
		char_padding(pf, '-');
	if ((!(pf->flags & F_ZERO) && pf->flags & F_PLUS && nb >= 0)
		|| pf->flags & F_SPACE)
		(pf->flags & F_SPACE) ? char_padding(pf, ' ') : char_padding(pf, '+');
}

int				f_conv(t_printf *pf, long double nb, int prec)
{
	intmax_t	n;

	n = (intmax_t)nb;
	f_flags_padding(pf, nb);
	ft_putllnbr(pf, n);
	prec ? char_padding(pf, '.') : 0;
	nb -= (intmax_t)nb;
	while (prec != 0)
	{
		nb *= 10;
		n = (intmax_t)nb % 10;
		nb -= (intmax_t)nb;
		if (pf->last_up + prec <= pf->precision)
		{
			if (pf->last_up + prec == pf->precision)
				n = (n > 0) ? n + pf->extended_prec : -n + pf->extended_prec;
			else if ((n == 9 || n == -9) && pf->extended_prec)
				n = 0;
			n = (n == 10) ? 0 : n;
		}
		char_padding(pf, (ft_abs(n) + 48));
		prec--;
	}
	return (1);
}
