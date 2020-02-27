/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:49:32 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/27 12:04:16 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_num(const char *format, t_flags *f)
{
	/*if ((format[f->i] == '0') && (format[f->i--] == '%'))			//ONLY FOR NUMBER USING 0 INSTEAD OF .
	{
		printf("entra");
		f->i++;
		f->i++;
		f->flag_precision = ft_atoi(&format[f->i]);
		not_show_num(format, f);
	}*/
	//f->i++;
	f->width = ft_atoi(&format[f->i]);
	not_show_num(format, f);
	if (format[f->i] == '.')
	{
		f->punto = 1;
		f->i++;
		f->flag_precision = ft_atoi(&format[f->i]);
		not_show_num(format, f);
	}
}

void	flag_sig(const char *format, t_flags *f)
{
	if (format[f->i] == '-')
	{
		f->menos = 1;
		f->i++;
	}
	if (format[f->i] == '*')
	{
		f->flag_width += va_arg(f->ap, int);
		f->i++;
	}
	
	not_show_sig(format, f);
	not_show_num(format, f);
}