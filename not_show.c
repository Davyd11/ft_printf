/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:38:28 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/03 14:01:21 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void not_show_sig(const char *format, t_flags *f)
{
	if ((format[f->i] == '.') || 
	(format[f->i] >= '0' && format[f->i] <= '9'))
	{
		f->i++;
		if (format[f->i] != '*')
		{
			f->i--;
			flag_num(format, f);
		}
		if (format[f->i] == '*')
			flag_sig(format, f);
	}
		
}
void not_show_num(const char *format, t_flags *f)
{
	while (format[f->i] >= '0' && format[f->i] <= '9')						// MAKES THE FLAG NOT PRINTABLE
	{
		f->i++;
	}
	if (ft_strchr("-*", format[f->i]))
		flag_sig(format, f);
}