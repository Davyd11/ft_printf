/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davyd11 <davyd11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:49:32 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/26 21:16:21 by davyd11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_num(const char *format, t_flags *f)
{
	f->width = ft_atoi(&format[f->i]);
	//printf("%c", format[f->i]);
	not_show_num(format, f);
	if (format[f->i] == '.')
	{
		f->i++;
		f->flag_precision = ft_atoi(&format[f->i]);
		not_show_num(format, f);
	}
	/*if (format[f->i] == '0' || format[f->i] == '.')
		f->precision = 1;
	if (format[f->i] == '.')													//IN THE CASE OF A . WE WILL ADD A EXTRA 0
		f->flag_width++;														//IN THE CASE OF A . WE WILL ADD A EXTRA 0
	f->i++;
	if (format[f->i] == '*')
	{
		f->flag_width += va_arg(f->ap, int);
		f->i++;
	}
	else
	{	f->i--;																	//ALL THE SUMS AND SUBS ARE USE TO KNOW IF THERE HAS BEEN ANY CHARCTERS PREVIUSLY OR NONE
		if (format[f->i--] == '%')
			f->i++;
		else
		{
			f->i++;
			f->i++;
		}
		f->flag_width = ft_atoi(&format[f->i]);
		not_show_num(format, f);
	}*/
}

void	flag_sig(const char *format, t_flags *f)
{
	if (format[f->i] == '-')
		f->precision = 3;
	if (format[f->i] == '*')
	{
		f->flag_width += va_arg(f->ap, int);
		f->i++;
	}
	else
	{
		not_show_sig(format, f);
		not_show_num(format, f);
	}
}
//-0.*