/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:44:19 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/12 17:38:50 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			w_conv(t_printf *pf, wint_t wc)
{
	int		min;
	int		i;

	if (!(i = w_charlen(wc)))
	{
		pf->ret = -1;
		return (1);
	}
	min = pf->min_length ? pf->min_length - i : 0;
	if (pf->flags & F_MINUS)
	{
		handle_buff(pf, get_wchar(wc), 0, i);
		min_padding(pf, ' ', min);
	}
	else
	{
		min_padding(pf, ' ', min);
		handle_buff(pf, get_wchar(wc), 0, i);
	}
	return (1);
}

int			c_conv(t_printf *pf, char c)
{
	int		min;

	min = pf->min_length ? pf->min_length - 1 : 0;
	if (pf->flags & F_MINUS)
	{
		char_padding(pf, c);
		min_padding(pf, ' ', min);
	}
	else
	{
		(pf->flags & F_ZERO) ? min_padding(pf, '0', min) :
		min_padding(pf, ' ', min);
		char_padding(pf, c);
	}
	return (1);
}

int			c_arg(t_printf *pf)
{
	wint_t	wc;
	char	c;

	if ((pf->flags & S_LONG) || (pf->conv == 'C'))
	{
		wc = va_arg(pf->ap, wint_t);
		w_conv(pf, wc);
	}
	else
	{
		c = va_arg(pf->ap, int);
		c_conv(pf, c);
	}
	return (1);
}
