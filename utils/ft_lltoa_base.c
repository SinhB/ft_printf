/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:16:48 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/13 19:00:14 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_nbrlen(uintmax_t nb, intmax_t base)
{
	int				len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len += 1;
	}
	return (len);
}

char				*ft_lltoa_base(uintmax_t n, intmax_t base)
{
	uintmax_t		n_size;
	static char		str[22];
	char			*strbase;

	ft_bzero(str, 22);
	strbase = "0123456789abcdef";
	n_size = ft_nbrlen(n, base);
	str[n_size] = '\0';
	while (n_size--)
	{
		str[n_size] = strbase[(n % base)];
		n /= base;
	}
	return (str);
}
