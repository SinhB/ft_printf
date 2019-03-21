/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:51:12 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/12 19:00:02 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_plus(t_printf *pf, int len, int prec)
{
	if (pf->flags & F_PLUS)
	{
		char_padding(pf, '+');
		if (len >= pf->precision)
			prec -= 1;
	}
	return (prec);
}

int		check_ohash(t_printf *pf, int prec)
{
	if (pf->flags & F_HASH)
	{
		hash_padding(pf);
		prec -= 1;
	}
	return (prec);
}

int		check_xhash(t_printf *pf, int prec, int nb)
{
	if ((pf->flags & F_HASH) && nb != 0)
	{
		hash_padding(pf);
		prec = pf->precision ? prec : prec - 2;
	}
	return (prec);
}

int		check_zero(t_printf *pf, int len)
{
	int prec;

	if (pf->flags & F_ZERO)
	{
		prec = pf->precision ? pf->precision - len :
				(pf->min_length - len - pf->neg);
		if ((pf->flags & F_SPACE) && (pf->precision == 0))
			prec -= 1;
	}
	else
		prec = pf->precision ? pf->precision - len : 0;
	prec = prec < 0 ? 0 : prec;
	return (prec);
}
