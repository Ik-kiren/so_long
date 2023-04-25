/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:24:06 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/25 17:37:59 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*len_malloc(char const *s, size_t len)
{
	char	*tab;
	size_t	length;

	length = len + 1;
	if (len > ft_strlen(s))
	length = ft_strlen(s) + 1;
	tab = (char *)malloc(sizeof(char) * length);
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tab;

	i = start;
	j = 0;
	tab = len_malloc(s, len);
	if (tab == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		tab[j] = '\0';
		return (tab);
	}
	while (s[i])
	{
		if (i >= start && j < len)
		{
			tab[j] = s[i];
			j++;
		}
		i++;
	}
	tab[j] = '\0';
	return (tab);
}
