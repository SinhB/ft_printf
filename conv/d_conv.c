/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:37:08 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/05 00:25:37 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int			d_conv(t_printf *pf, intmax_t nb, uintmax_t new)
{
	int		len;
	int		min;
	int		prec;

	new = check_neg(pf, nb, new);
	len = ft_nbrlen(new, pf->base);
	if (pf->precision == -1 && nb == 0)
		len = 0;
	prec = check_zero(pf, len);
	min = pf->min_length ? (pf->min_length - prec - len) : 0;
	if ((pf->flags & F_PLUS) || (pf->flags & F_SPACE) || pf->neg)
		min -= 1;
	if (pf->flags & F_MINUS)
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
