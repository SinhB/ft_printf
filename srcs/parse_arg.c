/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:37:12 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/27 12:10:32 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_options(t_printf *pf)
{
	int res;

	while ((res = find_char("-+0 #", *pf->format)) && pf->format++)
		pf->flags |= res;
	if (((pf->flags & F_ZERO) == F_ZERO) && ((pf->flags & F_MINUS) == F_MINUS))
		pf->flags &= ~F_MINUS;
	if (((pf->flags & F_PLUS) == F_PLUS) && ((pf->flags & F_SPACE) == F_SPACE))
		pf->flags &= ~F_SPACE;
}

void	get_min_length(t_printf *pf)
{
	if (*pf->format >= 49 && *pf->format <= 57)
		pf->min_length = ft_atoi(pf->format);
	if (*pf->format == '*')
		pf->min_length = va_arg(pf->ap, int);
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
			pf->precision = va_arg(pf->ap, int);
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

int	parse_arg(t_printf *pf)
{
	get_options(pf);
	get_min_length(pf);
	get_precision(pf);
	get_specifiers(pf);
	if (!get_conversion(pf))
		return (0);
	conv_to_fct(pf);
	/*printf("pf.formatafter = %s\n", pf->format);
	printf("flags1 = %d\n", pf->flags);
	printf("min_length = %d\n", pf->min_length);
	printf("precision = %d\n", pf->precision);*/
	return (1);
}
