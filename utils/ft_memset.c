/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:07:26 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/25 12:26:45 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char *tmp;

	tmp = s;
	while (n--)
		*tmp++ = c;
	return (s);
}
