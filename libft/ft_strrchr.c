/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:23:14 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/25 16:29:42 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char) c)
		{
			temp = (char *)&s[i];
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		temp = (char *)&s[i];
	if (temp != NULL)
	{
		return (temp);
	}
	else
	{
		return (NULL);
	}
}
