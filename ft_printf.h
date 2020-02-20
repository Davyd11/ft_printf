/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:54:52 by dpuente-          #+#    #+#             */
/*   Updated: 2020/02/20 14:12:55 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>//////////////////////////////////

#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct	s_flags
{
	va_list		ap;
	int			len;
	int			i;
	int			flag_width;					// Length of spaces or ceros
	int			var_width;						// LENGTH OF THE VARIABLE TO COMPARE
	int			flag_precision;				// DEPENDS OF THE NUMERS INDICATES WHAT IS THE CASE EXACTLY
	int			precision;
}				t_flags;

int			ft_printf(char *format, ...);

void 		int_format(t_flags *f);
void		spaces(t_flags *f);

//void 		str_format(t_flags *f);
//void		single_char(t_flags *f);

void		flag_num(const char *format, t_flags *f);
//void		flag_sig(const char *format, t_flags *f);