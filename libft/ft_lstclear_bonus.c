/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpuente- <dpuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 12:02:08 by dpuente-          #+#    #+#             */
/*   Updated: 2019/12/04 20:02:18 by dpuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp;

	tmp = *lst;
	if (!lst)
		return ;
	while (tmp)
	{
		del(tmp->content);
		free(tmp);
		tmp = tmp->next;
	}
	*lst = NULL;
}
