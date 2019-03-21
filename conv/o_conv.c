/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 10:24:55 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/05 00:25:33 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		o_conv(t_printf *pf, uintmax_t nb)
{
	int		len;
	int		min;
	int		prec;

	len = ft_nbrlen(nb, pf->base);
	if ((pf->precision == -1 || pf->flags & F_HASH) && nb == 0)
		len = 0;
	prec = check_zero(pf, len);
	min = pf->min_length ? (pf->min_length - prec - len) : 0;
	if ((pf->flags & F_HASH) && (len >= pf->precision))
		min -= 1;
	if (pf->flags & F_MINUS)
	{
		prec = check_ohash(pf, prec);
		u_padding(pf, prec, len, nb);
		min_padding(pf, ' ', min);
	}
	else
	{
		min_padding(pf, ' ', min);
		prec = check_ohash(pf, prec);
		u_padding(pf, prec, len, nb);
	}
	return (1);
}
