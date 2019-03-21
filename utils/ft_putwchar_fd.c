/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:12:45 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/02 11:11:31 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wchar_t wc, int fd)
{
	char	tab[5];

	ft_strclr(tab);
	if (wc <= 0x7F)
		write(fd, &wc, 1);
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
	ft_putstr_fd(tab, fd);
}
