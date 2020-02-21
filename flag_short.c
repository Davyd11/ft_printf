/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:49:32 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/21 16:45:23 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_num(const char *format, t_flags *f)
{
	if (format[f->i] == '0' || format[f->i] == '.')
		f->precision = 1;
	if (format[f->i] == '.')													//IN THE CASE OF A . WE WILL ADD A EXTRA 0
		f->flag_width++;														//IN THE CASE OF A . WE WILL ADD A EXTRA 0
	f->i++;
	f->flag_width += ft_atoi(&format[f->i]);									// THE VALUE OF THE NUMBER AFTER %
	not_show_num(format, f);
	
}

void	flag_sig(const char *format, t_flags *f)
{
	if (format[f->i] == '-')
		f->precision = 3;
	
	not_show_sig(format, f);
	not_show_num(format, f);
}
//-0.*