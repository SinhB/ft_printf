/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:45:10 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/12 17:43:58 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wstr_tobuff(t_printf *pf, wchar_t *str, int len)
{
	int i;
	int cnt;
	int prec;

	cnt = 0;
	prec = len;
	while (*str && (len > 0))
	{
		i = w_charlen(*str);
		cnt += i;
		if (cnt <= prec)
			handle_buff(pf, get_wchar(*str), 0, i);
		str++;
		len -= i;
	}
}

int		get_minwchar(t_printf *pf, wchar_t *str, int len)
{
	int		i;
	int		j;
	int		cnt;
	int		prec;

	cnt = 0;
	prec = len;
	j = 0;
	while (*str && (len > 0))
	{
		i = w_charlen(*str);
		cnt += i;
		if (cnt <= prec)
			j += i;
		str++;
		len -= i;
	}
	return (pf->min_length - j < 0 ? 0 : pf->min_length - j);
}

int		ws_conv(t_printf *pf, wchar_t *str)
{
	int		len;
	int		min;

	len = str ? ft_wstrlen(str) : 6;
	if (pf->precision && pf->precision != -1)
		len = len > pf->precision ? pf->precision : len;
	else if (pf->precision == -1)
		len = 0;
	min = str ? get_minwchar(pf, str, len) : get_minwchar(pf, L"(null)", len);
	if (pf->flags & F_MINUS)
	{
		str ? wstr_tobuff(pf, str, len) : handle_buff(pf, "(null)", 0, len);
		min_padding(pf, ' ', min);
	}
	else
	{
		(pf->flags & F_ZERO) ? min_padding(pf, '0', min) :
		min_padding(pf, ' ', min);
		str ? wstr_tobuff(pf, str, len) : handle_buff(pf, "(null)", 0, len);
	}
	return (1);
}

int		s_conv(t_printf *pf, char *str)
{
	int		len;
	int		min;

	len = str ? ft_strlen(str) : 6;
	if (pf->precision && pf->precision < len)
		len = (pf->precision == -1) ? 0 : pf->precision;
	min = pf->min_length ? pf->min_length - len : 0;
	if (pf->flags & F_MINUS)
	{
		str ? handle_buff(pf, str, 0, len) : handle_buff(pf, "(null)", 0, len);
		min_padding(pf, ' ', min);
	}
	else
	{
		(pf->flags & F_ZERO) ? min_padding(pf, '0', min) :
		min_padding(pf, ' ', min);
		str ? handle_buff(pf, str, 0, len) : handle_buff(pf, "(null)", 0, len);
	}
	return (1);
}

int		s_arg(t_printf *pf)
{
	char	*str;
	wchar_t *wstr;

	if ((pf->flags & S_LONG) || (pf->conv == 'S'))
	{
		wstr = va_arg(pf->ap, wchar_t*);
		ws_conv(pf, wstr);
	}
	else
	{
		str = va_arg(pf->ap, char*);
		s_conv(pf, str);
	}
	return (1);
}
