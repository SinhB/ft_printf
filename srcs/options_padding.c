/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:16:47 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/13 19:00:54 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_padding(t_printf *pf, char c)
{
	check_buff(pf);
	pf->buff[pf->index] = c;
	pf->index++;
}

void	hash_padding(t_printf *pf)
{
	char_padding(pf, '0');
	check_buff(pf);
	if (pf->conv == 'x' || pf->conv == 'p')
		pf->buff[pf->index++] = 'x';
	else if (pf->conv == 'X')
		pf->buff[pf->index++] = 'X';
}

void	padding(t_printf *pf, int prec, int len, uintmax_t nb)
{
	prec = check_plus(pf, len, prec);
	(pf->flags & F_SPACE) ? char_padding(pf, ' ') : 0;
	pf->neg ? char_padding(pf, '-') : 0;
	min_padding(pf, '0', prec);
	if (pf->conv == 'X')
		handle_buff(pf, to_upper(ft_lltoa_base(nb, pf->base)), 0, len);
	else
		handle_buff(pf, ft_lltoa_base(nb, pf->base), 0, len);
}

void	u_padding(t_printf *pf, int prec, int len, uintmax_t nb)
{
	min_padding(pf, '0', prec);
	if (pf->conv == 'X')
		handle_buff(pf, to_upper(ft_lltoa_base(nb, pf->base)), 0, len);
	else
		handle_buff(pf, ft_lltoa_base(nb, pf->base), 0, len);
}

void	min_padding(t_printf *pf, char c, int len)
{
	if (len > 0)
		while (len--)
			char_padding(pf, c);
}
