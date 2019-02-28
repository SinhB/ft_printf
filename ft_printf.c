/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:56:38 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/27 16:58:26 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.format = (char*)format;
	va_start (pf.ap, format);
	while (*pf.format)
	{
		check_buff(&pf);
		if (*pf.format == '%')
		{
			pf.format++;
			if (!parse_arg(&pf))
				return (end(&pf, 0));
			reset_struct(&pf);
		}
		else
			pf.buff[pf.index++] = *pf.format++;
	}
	return (end(&pf, 1));
}
