/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:44:47 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/28 16:45:23 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int			int_arg(t_printf *pf)
{
	intmax_t	nb;
	uintmax_t 	unb;
	uintmax_t 	new;

	new = 0;
	nb = 0;
	unb = 0;
	if (pf->conv == 'd' || pf->conv == 'i')
		nb = ft_castint(pf);
	else if (pf->conv == 'o' || pf->conv == 'u' || pf->conv == 'x' || pf->conv == 'X')
		unb = ft_castuint(pf);
	if (pf->conv == 'd' || pf->conv == 'i')
		d_conv(pf, nb, new);
	if (pf->conv == 'o')
		u_conv(pf, unb);
	if (pf->conv == 'u' || pf->conv == 'b')
		u_conv(pf, unb);
	if (pf->conv == 'x' || pf->conv == 'X')
		u_conv(pf, unb);
	return (1);
}
