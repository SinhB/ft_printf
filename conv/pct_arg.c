/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:45:06 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/28 17:01:02 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		pct_arg(t_printf *pf)
{
	int i;

	i = pf->min_length ? pf->min_length - 1 : 0;
	if ((pf->flags & F_MINUS) == F_MINUS)
	{
		plus_padding(pf, '%');
		min_padding(pf, ' ', i);
	}
	else
	{
		if ((pf->flags & F_ZERO) == F_ZERO)
			min_padding(pf, '0', i);
		else
			min_padding(pf, ' ', i);
		plus_padding(pf, '%');
	}
	return (1);
}
