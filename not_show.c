/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:38:28 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/27 12:02:10 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void not_show_sig(const char *format, t_flags *f)
{
	if ((format[f->i] == '.') || 
	(format[f->i] >= '0' && format[f->i] <= '9'))
		flag_num(format, f); 
	if (format[f->i] == '*')
	{
		f->flag_width += va_arg(f->ap, int);
		f->i++;
	}
	else	
		f->flag_width = ft_atoi(&format[f->i]);
}
void not_show_num(const char *format, t_flags *f)
{
	while (format[f->i] >= '0' && format[f->i] <= '9')						// MAKES THE FLAG NOT PRINTABLE
	{
		f->i++;
	}
}