/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   man_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybecret <ybecret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 18:35:03 by ybecret           #+#    #+#             */
/*   Updated: 2019/03/13 19:06:26 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*intro(void)
{
	char *str;

	str = "					\033[1m FT_PRINTF \033[0m\n\
\033[1m NAME \033[0m\n\
	ft_printf\n\
\033[1m SYNOPSIS \033[0m\n\
	ft_printf format [arguments ...]\n\
\033[1m DESCRIPTION \033[0m\n\
	The ft_printf utility formats and prints its arguments, after the first,\n\
	under control of the format.  The format is a character string which con-\n\
	tains three types of objects: plain characters, which are simply copied\n\
	to standard output, character escape sequences which are converted and\n\
	copied to the standard output, and format specifications, each of which\n\
	causes printing of the next successive argument.\n\n\
\
	The arguments after the first are treated as strings if the corresponding\n\
	format is either c, b or s; otherwise it is evaluated as a C constant,\n\
	with the following extensions:\n\n\
\
		o   A leading plus or minus sign is allowed.\n\
		o   If the leading character is a single or double quote, the value\n\
			is the character code of the next character.\n\n";
	return (str);
}

char	*firstact(void)
{
	char *str;

	str = "					\033[1m CONVERSIONS \033[0m\n\n\
	Each format specification is introduced by the percent character (``%'').\n\
	The remainder of the format specification includes, in the following\n\
	order:\n\n\
	Zero or more of the following flags:\n\
					\033[1;33m\033[1m # - + space 0 \033[0m\n\n\
	Field Width:\n\
		An optional digit string specifying a field width; if the output\n\
		string has fewer bytes than the field width it will be blank-\n\
		padded on the left (or right, if the left-adjustment indicator\n\
		has been given) to make up the field width (note that a leading\n\
		zero is a flag, but an embedded zero is part of a field width);\n\n\
	Precision:\n\
		An optional period, `.', followed by an optional digit string\n\
		giving a precision which specifies the number of digits to appear\n\
		after the decimal point, for f formats, or the maximum number of\n\
		bytes to be printed from a string; if the digit string is\n\
		missing, the precision is treated as zero;\n";
	return (str);
}

char	*secondact(void)
{
	char *str;

	str = "\
	Format:\n\
		A character which indicates the type of format to use :\n\
				\033[1;33m\033[1m sSpdDioOuUxXcCfbB % M \033[0m\n\
		The uppercase formats differ from their lowercase counterparts\n\
		only in that the output of the former is entirely in uppercase.\n\
		The floating-point format specifiers\n\
					\033[1;33m\033[1m fF \033[0m\n\
		may be prefixed by an L to request that additional\n\
		precision be used, if available.\n\n\
	\033[1;33m\033[1m%\033[0m           Print a `%'; no argument is used.\n\n\
	\033[1;33m\033[1mM\033[0m           If you read this, you already know.\n\n\
	A field width or precision may be `\033[1;33m\033[1m*\033[0m' instead of a\
	digit string.  In this\n\
	case an argument supplies the field width or precision.\n\n";
	return (str);
}

char	*theend(void)
{
	char *str;

	str = "					\033[1m COLORS \033[0m\n\n\
	Colors:\n\
		ANSI codes are used to give some joy and pleasure when using the\n\
		ft_printf function.\n\
		It is written as follow\n\
				\033[1;33m\033[1m {color_name} \033[0m\n\
		and it can be written everywhere in the format string.\n\
		Available colors :\n\
		\033[47m\033[1;30m{black}\033[49m\n\
			\033[1;31m {red}\n\
				\033[1;32m {green}\n\
					\033[1;33m {yellow}\n\
						\033[1;34m {blue}\n\
							\033[1;35m {violet}\n\
								\033[1;36m {cyan}\n\
									\033[1;37m {white}\n\
		\033[0m {reset} --> reset color / bold to default (white).\n\
		\033[1m {bold} \033[0m--> write the text in \033[1mbold\033[0m.\n\
		 \033[4m{underline}\033[0m --> \033[4munderline\033[0m the text.\n\n";
	return (str);
}

int		man_arg(t_printf *pf)
{
	pf->index = 0;
	handle_buff(pf, intro(), 0, 890);
	handle_buff(pf, firstact(), 0, 916);
	handle_buff(pf, secondact(), 0, 670);
	handle_buff(pf, theend(), 0, 606);
	return (1);
}
