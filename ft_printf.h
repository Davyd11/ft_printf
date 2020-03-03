/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:54:52 by dpuente-          #+#    #+#             */
/*   Updated: 2020/03/03 14:21:48 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft/libft.h"

typedef struct	s_flags
{
	va_list		ap;
	int			len;
	int			i;
	int			fast;
	int			width;
	int			flag_width;/////////////////// Length of spaces or ceros//////////DELETE
	int			var_width;
	int			flag_precision;				// DEPENDS OF THE NUMERS INDICATES WHAT IS THE CASE EXACTLY
	int			precision;					// USE TO KNOW WHAT KIND OF FLAG ARE WE WORKING WITH
	int			punto;						// USE TO CHECK IF THERE IS ANY DOT
	int			menos;
	int			done;						//IF TRUE NUMBERS HAVE PRINT AND SPACES CAN BE PRINTENTED AFTER IF THERE IS A - IN THE FLAG
}				t_flags;

int			ft_printf(char *format, ...);

void 		int_format(t_flags *f);
void		spaces(t_flags *f, long int n);
int			ceros(t_flags *f, long int n);
void	 	ft_print_int(long int n, t_flags *f);

void 		str_format(t_flags *f);
void		single_char(t_flags *f);
void 		spaces_char(t_flags *f);

void		flag_num(const char *format, t_flags *f);
void		flag_sig(const char *format, t_flags *f);

void		not_show_sig(const char *format, t_flags *f);
void		not_show_num(const char *format, t_flags *f);

void		uns_int(t_flags *f);
void		point_add(t_flags *f);

void		hex_x(t_flags *f, char *letters);
void		hex_pointer(t_flags *f, char *letters);