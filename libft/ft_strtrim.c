/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:23:29 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/25 12:33:03 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*searchstr(char const *s1, int j, int start)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * (j - start + 1));
	if (!tab)
		return (NULL);
	while (start < j)
	{
		tab[i] = s1[start];
		i++;
		start++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	j;
	int	start;

	j = 0;
	start = 0;
	while (s1[j])
	{
		if (ft_strchr(set, s1[j]) == 0)
			break ;
		j++;
	}
	if (s1[j] == '\0')
		return (searchstr(s1, j, j));
	start = j;
	j = ft_strlen(s1);
	while (j >= 0)
	{
		if (ft_strchr(set, s1[j]) == 0)
			break ;
		j--;
	}
	return (searchstr(s1, j + 1, start));
}
