/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:49:32 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/20 13:36:30 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flag_num(const char *format, t_flags *f)
{
	f->flag_width = ft_atoi(&format[f->i]);									// THE VALUE OF THE NUMBER AFTER %
	f->flag_precision++;
	while (format[f->i] >= '0' && format[f->i] <= '9')						// MAKES THE FLAG NOT PRINTABLE
	{
		f->i++;
	}
	printf("ENTRA EN FLAGS");
}