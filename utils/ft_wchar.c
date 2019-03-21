/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 17:38:36 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/12 17:38:47 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		w_charlen(wint_t wc)
{
	if (wc <= 0x7F)
		return (1);
	else if (wc <= 0x7FF)
		return (2);
	else if (wc <= 0xFFFF)
		return (3);
	else if (wc <= 0x1FFFFF)
		return (4);
	return (0);
}

char		*get_wchar(wint_t wc)
{
	static char	tab[5];

	ft_bzero(tab, 5);
	if (wc <= 0x7F)
		tab[0] = wc;
	else if (wc <= 0x7FF)
	{
		tab[0] = (wc >> 6) + 0xC0;
		tab[1] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0xFFFF)
	{
		tab[0] = (wc >> 12) + 0xE0;
		tab[1] = ((wc >> 6) & 0x3F) + 0x80;
		tab[2] = (wc & 0x3F) + 0x80;
	}
	else if (wc <= 0x1FFFFF)
	{
		tab[0] = (wc >> 18) + 0xF0;
		tab[1] = ((wc >> 12) & 0x3F) + 0x80;
		tab[2] = ((wc >> 6) & 0x3F) + 0x80;
		tab[3] = (wc & 0x3F) + 0x80;
	}
	return (tab);
}
