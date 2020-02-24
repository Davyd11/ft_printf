/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:49:29 by davyd11           #+#    #+#             */
/*   Updated: 2019/11/20 16:46:49 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n;
	int		p;
	int		size;
	char	*join;

	p = 0;
	n = 0;
	if (!s1)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(join = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[n] != '\0')
	{
		join[n] = s1[n];
		n++;
	}
	while (s2[p] != '\0')
	{
		join[n] = s2[p];
		p++;
		n++;
	}
	join[n] = '\0';
	return (join);
}
