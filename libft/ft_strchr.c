/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:16:51 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/25 16:30:19 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}
