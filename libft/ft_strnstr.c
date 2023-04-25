/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:22:22 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/24 14:16:57 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
	{
		return ((char *)haystack);
	}
	while (i < n && haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < n)
		{
			if (needle[j + 1] == '\0')
			{
				return ((char *)haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
