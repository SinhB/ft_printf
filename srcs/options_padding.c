/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_padding.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:16:47 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/28 17:31:13 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	hash_padding(t_printf *pf)
{
	check_buff(pf);
	pf->buff[pf->index++] = '0';
	check_buff(pf);
	if (pf->conv == 'x' || pf->conv == 'p')
		pf->buff[pf->index++] = 'x';
	else
		pf->buff[pf->index++] = 'X';
}

void	padding(t_printf *pf, int prec, int len, uintmax_t nb)
{
	((pf->flags & F_PLUS) == F_PLUS) ? plus_padding(pf, '+') : 0;
	((pf->flags & F_SPACE) == F_SPACE) ? plus_padding(pf, ' ') : 0;
	pf->neg ? plus_padding(pf, '-') : 0;
	min_padding(pf, '0', prec);
	handle_buff(pf, ft_lltoa_base(nb, pf->base), 0, len);
}

void	min_padding(t_printf *pf, char c, int len)
{
	if (len > 0)
	{
		while (len--)
		{
			check_buff(pf);
			pf->buff[pf->index++] = c;
		}
	}
}

void	plus_padding(t_printf *pf, char c)
{
	check_buff(pf);
	pf->buff[pf->index++] = c;
}
