/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 13:17:45 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/24 13:36:50 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_to_zero(t_flags *f)
{
	f->flag_width = 0;
	f->var_width = 0;
	f->flag_precision = 0;
	f->precision = 0;
	f->done = 0;
}

void format_sorting(const char *format, t_flags *f)								// send to specific function depending on flag
{																				// cspdiuxX% //
	if (format[f->i] == 'c')
		single_char(f);
	if (format[f->i] == 'd' || format[f->i] == 'i')								// finish the selection to aboid floats
		int_format(f);
	if (format[f->i] == 's')
		str_format(f);
}

void	percent_finder(const char *format, t_flags *f)
{
	while (format[f->i]) 														//While ther is a string to read (it will take actions character by character )
	{
		if (format[f->i] == '%')
		{
			f->i++;
			flags_to_zero(f);
			if (ft_strchr("-*", format[f->i]))
				flag_sig(format, f);
			if (ft_strchr(".0123456789", format[f->i]))
				flag_num(format, f);
			if (ft_strchr("cspdiuxX", format[f->i]))
				format_sorting(format, f);
		}
		else 																	// prints all text except for the %d ...
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
	if (ft_strchr(format, '%')) 												//go to search  if there is any %
	{
		percent_finder(format, &f);
	}
	else																		//just print on screen all text(no flags)
	{
		ft_putstr_fd(format, 0);
		f.len = ft_strlen(format);
	}
	va_end(f.ap);
	return (f.len);
}
