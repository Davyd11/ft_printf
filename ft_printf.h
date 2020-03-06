/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:54:52 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/06 13:19:04 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flags
{
	va_list		ap;
	int			len;
	int			i;
	int			fast;
	int			width;
	int			flag_width;
	int			var_width;
	int			flag_precision;
	int			precision;
	int			punto;
	int			menos;
	int			percent;
	int			done;
}				t_flags;

int				ft_printf(char *format, ...);
void			int_format(t_flags *f);
void			spaces(t_flags *f, long int n);
int				ceros(t_flags *f, long int n);
void			ft_print_int(long int n, t_flags *f);
void			spaces_after(t_flags *f, long int n);
void			format_utils(t_flags *f, long int n, int yes);
void			hex_pointer_utils(t_flags *f, char *letters,
unsigned long int n, int yes);
void			hex_putnbrbase(t_flags *f, unsigned long int n,
char *base, unsigned int baselen);
void			str_format(t_flags *f);
void			single_char(t_flags *f);
void			spaces_char(t_flags *f);
void			flag_num(const char *format, t_flags *f);
void			flag_sig(const char *format, t_flags *f);
void			not_show_sig(const char *format, t_flags *f);
void			not_show_num(const char *format, t_flags *f);
void			hex_putnbrbase_len(t_flags *f, long int n, char *base,
int baselen);
void			uns_int(t_flags *f);
void			point_add(t_flags *f);
void			hex_x(t_flags *f, char *letters);
void			hex_pointer(t_flags *f, char *letters);
void			percent(const char *format, t_flags *f);
#endif
