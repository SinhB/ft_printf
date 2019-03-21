/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 22:31:48 by ybecret           #+#    #+#             */
/*   Updated: 2019/03/13 16:50:48 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_minlen(t_printf *pf, long double nb, int prec)
{
	int			min;
	uintmax_t	n;

	min = pf->min_length;
	if (nb < 0)
	{
		min -= 1;
		nb = -nb;
	}
	n = (uintmax_t)nb;
	min -= (ft_nbrlen(n, B_DEC) + (prec + 1));
	min += (pf->precision == -1) ? 1 : 0;
	if (pf->flags & F_PLUS || pf->flags & F_SPACE)
		min -= 1;
	return (min);
}

int		check_infnan(t_printf *pf, long double nb)
{
	int		i;
	int		min;

	i = pf->index;
	if (!(isnan(nb) || isinf(nb)))
		return (1);
	min = (nb < 0.0) ? pf->min_length - 4 : pf->min_length - 3;
	(pf->flags & F_MINUS) ? 0 : min_padding(pf, ' ', min);
	if (isnan(nb) && pf->conv == 'F')
		handle_buff(pf, "NAN", 0, 3);
	else if (isnan(nb) && pf->conv == 'f')
		handle_buff(pf, "nan", 0, 3);
	else if (isinf(nb) && pf->conv == 'F' && nb < 0.0)
		handle_buff(pf, "-INF", 0, 4);
	else if (isinf(nb) && pf->conv == 'f' && nb < 0.0)
		handle_buff(pf, "-inf", 0, 4);
	else if (isinf(nb) && pf->conv == 'F' && nb >= 0.0)
		handle_buff(pf, "INF", 0, 3);
	else if (isinf(nb) && pf->conv == 'f' && nb >= 0.0)
		handle_buff(pf, "inf", 0, 3);
	(pf->flags & F_MINUS) ? min_padding(pf, ' ', min) : 0;
	return (i == pf->index ? 1 : 0);
}

void	f_padding(t_printf *pf, int prec, int min, long double nb)
{
	if (pf->flags & F_MINUS)
	{
		f_conv(pf, nb, prec);
		min_padding(pf, ' ', min);
	}
	else
	{
		(pf->flags & F_PLUS && pf->flags & F_ZERO) ? char_padding(pf, '+') : 0;
		(pf->flags & F_ZERO) ? min_padding(pf, '0', min) :
		min_padding(pf, ' ', min);
		f_conv(pf, nb, prec);
	}
}

int		f_arg(t_printf *pf)
{
	long double nb;
	int			prec;
	int			min;

	if (!pf->precision)
		pf->precision = 6;
	prec = (pf->precision == -1) ? 0 : pf->precision;
	if (pf->flags & S_DOUBLE)
		nb = va_arg(pf->ap, long double);
	else
		nb = va_arg(pf->ap, double);
	if (!check_infnan(pf, nb))
		return (1);
	nb = ft_round(pf, nb, prec);
	min = get_minlen(pf, nb, prec);
	f_padding(pf, prec, min, nb);
	return (1);
}
