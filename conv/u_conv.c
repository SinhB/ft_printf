/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:38:08 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/05 00:25:26 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			u_conv(t_printf *pf, uintmax_t nb)
{
	int		len;
	int		min;
	int		prec;

	len = ft_nbrlen(nb, pf->base);
	if (pf->precision == -1 && nb == 0)
		len = 0;
	prec = check_zero(pf, len);
	min = pf->min_length ? (pf->min_length - prec - len) : 0;
	if ((pf->flags & F_PLUS) || (pf->flags & F_SPACE) || pf->neg)
		min -= 1;
	if (pf->flags & F_MINUS)
	{
		u_padding(pf, prec, len, nb);
		min_padding(pf, ' ', min);
	}
	else
	{
		min_padding(pf, ' ', min);
		u_padding(pf, prec, len, nb);
	}
	return (1);
}
