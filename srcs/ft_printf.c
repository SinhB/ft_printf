/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:56:38 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/12 17:21:39 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_color(t_printf *pf)
{
	if (*pf->format == '{')
	{
		if (color_to_fct(pf) == -1)
		{
			char_padding(pf, *pf->format);
			pf->format++;
		}
	}
	else
	{
		char_padding(pf, *pf->format);
		pf->format++;
	}
}

int		ft_printf(const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.format = (char*)format;
	va_start(pf.ap, format);
	pf.fd = 1;
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			check_buff(&pf);
			parse_arg(&pf);
			reset_struct(&pf);
		}
		else
			check_color(&pf);
	}
	return (end(&pf, 1));
}

int		ft_dprintf(int fd, const char *format, ...)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.format = (char*)format;
	va_start(pf.ap, format);
	pf.fd = fd;
	while (*pf.format)
	{
		if (*pf.format == '%')
		{
			pf.format++;
			check_buff(&pf);
			parse_arg(&pf);
			reset_struct(&pf);
		}
		else
			check_color(&pf);
	}
	return (end(&pf, 1));
}
