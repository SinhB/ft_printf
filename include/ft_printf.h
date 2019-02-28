/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabecret <yabecret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:50:32 by yabecret          #+#    #+#             */
/*   Updated: 2019/02/28 19:54:03 by yabecret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFF_SIZE 64

# define ABS(Value) Value < 0 ? -Value : Value
# define MAX(a,b) a > b ? a : b
//# define egal(a,b) pf->conv == a || pf->conv == b

/* -------------------------------- FLAGS & SPEC ---------------------------- */

# define F_MINUS (1 << 0)  //  '-'
# define F_PLUS (1 << 1)   //  '+'
# define F_ZERO (1 << 2)   //  '0'
# define F_SPACE (1 << 3)  //  ' '
# define F_HASH (1 << 4)   //  '#'
# define S_SHORT (1 << 5)  //  'h'
# define S_LONG (1 << 6)   //  'l'
# define S_DOUBLE (1 << 7) //  'L'
# define S_INTMAX (1 << 8) //  'j'
# define S_SIZE_T (1 << 9) //  'z'
# define S_CHAR (1 << 10)  //  'hh'
# define S_LLONG (1 << 11) //  'll'

/* ----------------------------------- BASES ------------------------------- */

# define B_DEC 10
# define B_BIN (1 << 1)
# define B_OCT (1 << 3)
# define B_HEX (1 << 4)

/* ----------------------------------- STRUCT ------------------------------- */

typedef struct	s_printf
{
	int			flags;
	int			precision;
	int			min_length;
	int			neg;
	int			base;
	int			index;
	int			ret;
	va_list 	ap;
	char 		buff[BUFF_SIZE];
	char		*format;
	char		conv;
}				t_printf;

typedef  int(*t_f_conv)(t_printf*);

typedef struct	s_conv
{
	char 		*c;
	t_f_conv	funct;
}				t_conv;

int				ft_printf(const char *format, ...);

/* ----------------------------------- UTILS ------------------------------- */

size_t			ft_strlen(const char *str);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strcpy(char *dest, const char *src);
intmax_t		ft_atoi(char *s);
int				ft_isdigit(int c);
int				find_char(char *str, char c);
int				find_conv(char *str, char c);
char			*to_upper(char *str);

/* ---------------------------------- OPTIONS ------------------------------- */

int				parse_arg(t_printf *pf);

/* ---------------------------------- CONVERS ------------------------------- */

int				get_conversion(t_printf *pf);
int				conv_to_fct(t_printf *pf);
int				d_conv(t_printf *pf, intmax_t nb, uintmax_t new);
int				u_conv(t_printf *pf, uintmax_t nb);

/* ---------------------------------- CASTARG ------------------------------- */

intmax_t		ft_castint(t_printf *pf);
uintmax_t		ft_castuint(t_printf *pf);

/* ---------------------------------- PT_FUNCT ------------------------------ */

int				int_arg(t_printf *pf);
int				dou_arg(t_printf *pf);
int				c_arg(t_printf *pf);
int				s_arg(t_printf *pf);
int				p_arg(t_printf *pf);
int				pct_arg(t_printf *pf);

/* -------------------------------- HANDLE_BUFF ----------------------------- */

void			reset_struct(t_printf *pf);
void			reset(t_printf *pf);
void			check_buff(t_printf *pf);
int				end(t_printf *pf, int i);
int				handle_buff(t_printf *pf, char* str, int diff, int n);


/* ---------------------------------- PADDING ------------------------------- */

void			hash_padding(t_printf *pf);
void			padding(t_printf *pf, int prec, int len, uintmax_t nb);
void			min_padding(t_printf *pf, char c, int len);
void			plus_padding(t_printf *pf, char c);
int				check_zero(t_printf *pf, int len);
uintmax_t		check_neg(t_printf *pf, intmax_t nb, uintmax_t new);

/* ---------------------------------- NUMBERS ------------------------------- */

int				ft_nbrlen(uintmax_t nb, intmax_t base);
char			*ft_lltoa_base(uintmax_t nb, intmax_t base);

#endif
