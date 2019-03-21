/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:22:07 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/09 13:48:44 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(wchar_t *s)
{
	int i;

	i = 0;
	while (*s != L'\0')
	{
		i += w_charlen(*s);
		s++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
