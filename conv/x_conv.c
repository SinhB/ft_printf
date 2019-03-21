/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:20:27 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/05 00:25:29 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		x_conv(t_printf *pf, uintmax_t nb)
{
	int		len;
	int		min;
	int		prec;

	len = ft_nbrlen(nb, pf->base);
	if (pf->precision == -1 && nb == 0)
		len = 0;
	prec = check_zero(pf, len);
	min = pf->min_length ? (pf->min_length - prec - len) : 0;
	if ((pf->flags & F_HASH) && (nb != 0))
		min -= 2;
	if (pf->flags & F_MINUS)
	{
		prec = check_xhash(pf, prec, nb);
		u_padding(pf, prec, len, nb);
		min_padding(pf, ' ', min);
	}
	else
	{
		min_padding(pf, ' ', min);
		prec = check_xhash(pf, prec, nb);
		u_padding(pf, prec, len, nb);
	}
	return (1);
}
