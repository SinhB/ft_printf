/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:37:12 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/07 18:14:01 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_options(t_printf *pf)
{
	int res;

	while ((res = find_char("-+0 #", *pf->format)) && pf->format++)
		pf->flags |= res;
	if ((pf->flags & F_ZERO) && (pf->flags & F_MINUS))
		pf->flags &= ~F_ZERO;
	if ((pf->flags & F_PLUS) && (pf->flags & F_SPACE))
		pf->flags &= ~F_SPACE;
}

void	get_min_length(t_printf *pf)
{
	if (*pf->format >= 49 && *pf->format <= 57)
		pf->min_length = ft_atoi(pf->format);
	if (*pf->format == '*')
	{
		pf->format++;
		pf->min_length = va_arg(pf->ap, int);
		if (pf->min_length < 0)
			(pf->flags |= F_MINUS) && (pf->flags &= ~F_ZERO);
		pf->min_length = ft_abs(pf->min_length);
	}
	while (ft_isdigit(*pf->format) > 0)
		pf->format++;
}

void	get_precision(t_printf *pf)
{
	if (*pf->format == '.')
	{
		pf->format++;
		pf->precision = ft_atoi(pf->format) ? ft_atoi(pf->format) : -1;
		if (*pf->format == '*')
		{
			pf->format++;
			pf->precision = va_arg(pf->ap, int);
			if (pf->precision <= 0)
			{
				if (pf->precision == 0)
					pf->precision = -1;
				else
					pf->precision = 0;
			}
		}
		while (ft_isdigit(*pf->format) > 0)
			pf->format++;
	}
}

void	get_specifiers(t_printf *pf)
{
	int res;

	if ((res = find_char("hlLjz", *pf->format)))
	{
		res <<= 5;
		pf->format++;
		if (((res == 32) && (*pf->format == 'h')) ||
			((res == 64) && (*pf->format == 'l')))
		{
			res <<= 5;
			pf->format++;
		}
		pf->flags |= res;
	}
}

int		parse_arg(t_printf *pf)
{
	get_options(pf);
	get_min_length(pf);
	get_precision(pf);
	get_specifiers(pf);
	if (!get_conversion(pf))
		return (0);
	conv_to_fct(pf);
	return (1);
}
