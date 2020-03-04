/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:49:32 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/04 15:44:47 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_num(const char *format, t_flags *f)
{
	if (format[f->i] == '0')
	{
		if (format[f->i + 1] == '-')
			f->punto = 0;
		else
		{
			f->punto = 2;
			f->i++;
		}
	}
	if (format[f->i] == '*')
			flag_sig(format, f);
	else
		f->width = ft_atoi(&format[f->i]);
	if (f->punto == 2)
		f->flag_precision = f->width;
	not_show_num(format, f);
	if (format[f->i] == '.')
	{
		f->punto = 1;
		f->i++;
		if (format[f->i] == '*')
			flag_sig(format, f);
		else
		{
			f->flag_precision = ft_atoi(&format[f->i]);
			not_show_num(format, f);
		}
	}
}

void		flag_sig(const char *format, t_flags *f)
{
	if (format[f->i] == '-')
	{
		f->menos = 1;
		f->i++;
	}
	if (format[f->i] == '*')
	{	
		f->i--;
		if (format[f->i] == '.')
		{
			f->punto = 1;
			f->i++;
			f->flag_precision = va_arg(f->ap, int);
			f->i++;
		}
		else
		{
			f->i++;
			f->width = va_arg(f->ap, int);
			if (f->width < 0)
			{
				f->width *= -1;
				f->punto = 0;
				f->menos = 1;
			}
			f->i++;
		}
	}
	not_show_sig(format, f);
	not_show_num(format, f);
}

void		percent(const char *format, t_flags *f)
{
	write (1,&format,0);
	if (f->width > 0 || f->flag_precision > 0)
	{
		f->var_width = 1;
		if (f->width == 0 && f->punto == 0)
			f->width = f->flag_precision;
		f->flag_precision = 1;
		if ((f->fast != 1 && f->width > 1)&& f->menos == 0)
		{
			spaces(f, 1);
			ceros(f, 1);
		}
	}
	if (f->percent == 0)
	{
		write(1, &format[f->i], 1);
		f->len++;
	}
	f->done = 1;
	spaces(f, 1);
}