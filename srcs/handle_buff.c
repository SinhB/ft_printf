/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:34:13 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/12 17:16:53 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_struct(t_printf *pf)
{
	pf->flags = 0;
	pf->precision = 0;
	pf->min_length = 0;
	pf->neg = 0;
	pf->base = 0;
	pf->conv = 0;
	pf->extended_prec = 0;
	pf->last_up = 0;
}

int		end(t_printf *pf, int i)
{
	va_end(pf->ap);
	if (i == 1)
	{
		pf->buff[pf->index] = '\0';
		write(pf->fd, pf->buff, pf->index);
		return (pf->ret + pf->index);
	}
	return (-1);
}

void	reset(t_printf *pf)
{
	write(pf->fd, pf->buff, BUFF_SIZE - 1);
	ft_bzero(pf->buff, BUFF_SIZE);
	pf->ret += (BUFF_SIZE - 1);
	pf->index = 0;
}

void	check_buff(t_printf *pf)
{
	if (pf->index == BUFF_SIZE - 1)
		reset(pf);
}

int		handle_buff(t_printf *pf, char *str, int i, int n)
{
	int len;

	len = n - i;
	if (pf->index + len >= BUFF_SIZE - 1)
	{
		ft_memcpy(&pf->buff[pf->index], &str[i], ((BUFF_SIZE - 1) - pf->index));
		i += (BUFF_SIZE - 1) - pf->index;
		reset(pf);
		handle_buff(pf, str, i, n);
	}
	else
		while (len--)
			pf->buff[pf->index++] = str[i++];
	return (1);
}
