/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dou_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:44:39 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/28 12:36:35 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		dou_arg(t_printf *pf)
{
	intmax_t	nb;
	uintmax_t 	unb;
	uintmax_t 	new;

	new = 0;
	nb = 0;
	unb = 0;
	if (pf->conv == 'D')
		nb = ft_castint(pf);
	else
		unb = ft_castuint(pf);
	if (pf->conv == 'D')
		d_conv(pf, nb, new);
	if (pf->conv == 'O')
		d_conv(pf, unb, new);
	if (pf->conv == 'U')
		d_conv(pf, unb, new);
	return (1);
}
