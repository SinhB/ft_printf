/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 12:34:13 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/27 18:19:25 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	reset_struct(t_printf *pf)
{
	pf->flags = 0;
	pf->precision = 0;
	pf->min_length = 0;
	pf->neg = 0;
	pf->base = 0;
	pf->conv = 0;
}

int		end(t_printf *pf, int i)
{
	va_end(pf->ap);
	if (i == 1)
	{
		pf->buff[pf->index] = '\0';
		write(1, pf->buff, pf->index);
		return (pf->ret + pf->index);
	}
	return (-1);
}

void	reset(t_printf *pf)
{
	ft_putstr_fd(pf->buff, 1);
	ft_bzero(pf->buff, BUFF_SIZE);
	pf->ret += BUFF_SIZE;
	pf->index = 0;
}

void	check_buff(t_printf *pf)
{
	if (pf->index == BUFF_SIZE)
		reset(pf);
}

int		handle_buff(t_printf *pf, char* str, int diff, int n)
{
	int len;

//	len = ft_strlen(str) - diff;
	len = n - diff;
	if (pf->index + len >= BUFF_SIZE)
	{
		ft_memcpy(&pf->buff[pf->index], &str[diff], (BUFF_SIZE - pf->index));
		diff += BUFF_SIZE - pf->index;
		reset(pf);
		handle_buff(pf, str, diff, n);
	}
	else
		while (len--)
			pf->buff[pf->index++] = str[diff++];
	return (1);
}
