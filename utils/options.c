/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:40:31 by yabecret          #+#    #+#             */
/*   Updated: 2019/03/01 18:26:42 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1 << i);
		i++;
	}
	return (0);
}

int		find_conv(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str[i]);
		i++;
	}
	return (0);
}
