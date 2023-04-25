/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:09:16 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/24 14:18:09 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !f)
		return (NULL);
	tmp2 = ft_lstnew(f(lst->content));
	if (!tmp2)
	{
		ft_lstclear(&tmp, del);
		return (NULL);
	}
	tmp = tmp2;
	lst = lst->next;
	while (lst)
	{
		tmp2 = ft_lstnew(f(lst->content));
		ft_lstadd_back(&tmp, tmp2);
		lst = lst->next;
	}
	return (tmp);
}
