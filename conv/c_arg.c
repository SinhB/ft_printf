/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:44:19 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/27 00:30:01 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		w_char(t_printf *pf)
{
	printf("salut w_char %d\n", pf->flags);
	return (1);
}

int		c_conv(t_printf *pf)
{
	char	c;
	int		j;

	c = va_arg(pf->ap, int);
	j = pf->min_length ? pf->min_length - 1 : 0;
	if ((pf->flags & F_MINUS) == F_MINUS)
	{
		check_buff(pf);
		pf->buff[pf->index++] = c;
		min_padding(pf, ' ', j);
	}
	else
	{
		min_padding(pf, ' ', j);
		check_buff(pf);
		pf->buff[pf->index++] = c;
	}
	return (1);
}

int		c_arg(t_printf *pf)
{
	if (((pf->flags & S_LONG) == S_LONG) || (pf->conv == 'C'))
		w_char(pf);
	else
		c_conv(pf);
	return (1);
}
