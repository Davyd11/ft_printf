/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:17:45 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/09 18:06:20 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_to_zero(t_flags *f)
{
	f->var_width = 0;
	f->flag_precision = 0;
	f->precision = 0;
	f->done = 0;
	f->menos = 0;
	f->punto = 0;
	f->percent = 0;
}

void	format_sorting(const char *format, t_flags *f)
{
	f->i--;
	if (format[f->i] == '%')
		f->fast = 1;
	f->i++;
	if (format[f->i] == 'c' || format[f->i] == 'C')
		single_char(f);
	if (format[f->i] == 'd' || format[f->i] == 'i')
		int_format(f);
	if (format[f->i] == 's')
		str_format(f);
	if (format[f->i] == 'u')
		uns_int(f);
	if (format[f->i] == 'p')
		hex_pointer(f, "0123456789abcdef");
	if (format[f->i] == 'x')
		hex_x(f, "0123456789abcdef");
	if (format[f->i] == 'X')
		hex_x(f, "0123456789ABCDEF");
}

void	filter_percent(const char *format, t_flags *f)
{
	if (ft_strchr("-*", format[f->i]))
		flag_sig(format, f);
	if (ft_strchr(".0123456789", format[f->i]))
		flag_num(format, f);
	if (ft_strchr("%", format[f->i]) && f->percent == 0)
		percent(format, f);
	if (ft_strchr("cspdiuxX", format[f->i]))
		format_sorting(format, f);
}

void	percent_finder(const char *format, t_flags *f)
{
	while (format[f->i])
	{
		if (format[f->i] == '%')
		{
			if (format[f->i + 1])
				f->i++;
			else
				return ;
			if (format[f->i] == '#' && format[f->i + 1])
				f->i++;
			flags_to_zero(f);
			if (format[f->i] == '%')
			{
				write(1, &format[f->i], 1);
				f->len++;
				f->percent = 1;
				f->width -= 32766;
			}
			filter_percent(format, f);
		}
		else
		{
			write(1, &format[f->i], 1);
			f->len++;
		}
		f->i++;
	}
}

int		ft_printf(char *format, ...)
{
	t_flags f;

	f.len = 0;
	f.i = 0;
	va_start(f.ap, format);
	if (ft_strchr(format, '%'))
	{
		percent_finder(format, &f);
	}
	else
	{
		ft_putstr_fd(format, 1);
		f.len = ft_strlen(format);
	}
	va_end(f.ap);
	return (f.len);
}
