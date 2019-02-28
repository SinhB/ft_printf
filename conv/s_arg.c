/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:45:10 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/28 12:09:20 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		w_str(t_printf *pf)
{
	printf("salut w_char* %d\n", pf->flags);
	return (1);
}


int		s_conv(t_printf *pf)
{
	char	*str;
	int		i;
	int		j;

	str = va_arg(pf->ap, char*);
	i = str ? ft_strlen(str) : 6;
	if (pf->precision && pf->precision < i)
		i = (pf->precision == -1) ? 0 : pf->precision;
	j = pf->min_length ? pf->min_length - i : 0;
	if ((pf->flags & F_MINUS) == F_MINUS)
	{
		str ? handle_buff(pf, str, 0, i) : handle_buff(pf, "(null)", 0, i);
		min_padding(pf, ' ', j);
	}
	else
	{
		min_padding(pf, ' ', j);
		str ? handle_buff(pf, str, 0, i) : handle_buff(pf, "(null)", 0, i);
	}
	return (1);
}

int		s_arg(t_printf *pf)
{
	if (((pf->flags & S_LONG) == S_LONG) || (pf->conv == 'S'))
		w_str(pf);
	else
		s_conv(pf);
	return (1);
}
