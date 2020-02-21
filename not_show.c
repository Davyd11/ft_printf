/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:38:28 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/21 16:47:36 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void not_show_sig(const char *format, t_flags *f)
{
	/*while (format[f->i] == '-' || format[f->i] == '+'|| format[f->i] == '.'
	|| format[f->i] == ' ')													// MAKES THE FLAG NOT PRINTABLE
	{
		f->i++;
	}*/
	if (f->i++ == '.')
		flag_num(format, f); 
	f->flag_width = ft_atoi(&format[f->i]);
}
void not_show_num(const char *format, t_flags *f)
{
	while (format[f->i] >= '0' && format[f->i] <= '9')						// MAKES THE FLAG NOT PRINTABLE
	{
		f->i++;
	}
}