/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:37:08 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/28 16:02:16 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

uintmax_t	check_neg(t_printf *pf, intmax_t nb, uintmax_t new)
{
	if (nb < 0)
	{
		(pf->flags &= ~F_PLUS) && (pf->flags &= ~F_SPACE);
		new = -nb;
		pf->neg = 1;
	}
	else
		new = nb;
	return (new);
}

int			check_zero(t_printf *pf, int len)
{
	int prec;

	if ((pf->flags & F_ZERO) == F_ZERO)
	{
		prec = pf->precision ? pf->precision - len :
				(pf->min_length - len - pf->neg);
		if ((pf->flags & F_SPACE) == F_SPACE)
			prec -= 1;
	}
	else
		prec = pf->precision ? pf->precision - len : 0;
	prec = prec < 0 ? 0 : prec;
	return (prec);
}

int			d_conv(t_printf *pf, intmax_t nb, uintmax_t new)
{
	int		len;
	int		min;
	int		prec;

	new = check_neg(pf, nb, new);
	len = ft_nbrlen(new, pf->base);
	if (pf->precision == -1  && nb == 0)
		len = 0;
	prec = check_zero(pf, len);
	min = pf->min_length ? (pf->min_length - prec - len) : 0;
	if (((pf->flags & F_PLUS) == F_PLUS) || ((pf->flags & F_SPACE) == F_SPACE) || pf->neg)
		min -= 1;
	if ((pf->flags & F_MINUS) == F_MINUS)
	{
		padding(pf, prec, len, new);
		min_padding(pf, ' ', min);
	}
	else
	{
		min_padding(pf, ' ', min);
		padding(pf, prec, len, new);
	}
	return (1);
}
