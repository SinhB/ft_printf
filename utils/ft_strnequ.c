/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 13:56:21 by ybecret           #+#    #+#             */
/*   Updated: 2019/03/03 15:10:40 by ybecret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (n ? *(unsigned char*)s1 - *(unsigned char*)s2 : 0);
}

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (ft_strncmp(s1, s2, n) != 0 ? 0 : 1);
}
