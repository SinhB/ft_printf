/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:20:59 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/02 15:14:13 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_castint(t_printf *pf)
{
	if (pf->flags & S_INTMAX)
		return (va_arg(pf->ap, intmax_t));
	else if (pf->flags & S_SIZE_T)
		return (va_arg(pf->ap, ssize_t));
	else if (pf->flags & S_LLONG)
		return (va_arg(pf->ap, long long));
	else if ((pf->flags & S_LONG) || (pf->conv == 'D'))
		return (va_arg(pf->ap, long));
	else if (pf->flags & S_SHORT)
		return ((short)va_arg(pf->ap, int));
	else if (pf->flags & S_CHAR)
		return ((char)va_arg(pf->ap, int));
	return (va_arg(pf->ap, int));
}

uintmax_t	ft_castuint(t_printf *pf)
{
	if (pf->flags & S_INTMAX)
		return (va_arg(pf->ap, uintmax_t));
	else if (pf->flags & S_SIZE_T)
		return (va_arg(pf->ap, size_t));
	else if (pf->flags & S_LLONG)
		return (va_arg(pf->ap, unsigned long long));
	else if ((pf->flags & S_LONG) || (pf->conv == 'U') || (pf->conv == 'O'))
		return (va_arg(pf->ap, unsigned long));
	else if (pf->flags & S_SHORT)
		return ((unsigned short)va_arg(pf->ap, unsigned int));
	else if (pf->flags & S_CHAR)
		return ((unsigned char)va_arg(pf->ap, unsigned int));
	return (va_arg(pf->ap, unsigned int));
}
