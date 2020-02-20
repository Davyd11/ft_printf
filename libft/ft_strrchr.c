/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:08:11 by dpuente-          #+#    #+#             */
/*   Updated: 2019/11/22 17:08:45 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int		n;
	char	*word;

	n = 0;
	word = (char*)str;
	while (word[n] != '\0')
	{
		n++;
	}
	while (word[n] != c)
	{
		if (n <= 0)
			return (0);
		n--;
	}
	return (word + n);
}
