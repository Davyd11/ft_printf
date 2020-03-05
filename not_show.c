/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_show.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:38:28 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/05 11:52:19 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void not_show_sig(const char *format, t_flags *f)
{
	if ((format[f->i] == '.') || 
	(format[f->i] >= '0' && format[f->i] <= '9'))
	{
		if (format[f->i + 1])
			f->i++;
		else
			return ;
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
		if (format[f->i + 1])
			f->i++;
		else
			return ;
	}
	if (ft_strchr("-*", format[f->i]))
		flag_sig(format, f);
}

void	hex_putnbrbase_len(t_flags *f,long int n, char *base, int baselen)
{
	if (n >= baselen)
	{
		hex_putnbrbase_len(f, n / baselen, base, baselen);
		hex_putnbrbase_len(f, n % baselen, base, baselen);
	}
	else
	{
		f->var_width++;
	}
}