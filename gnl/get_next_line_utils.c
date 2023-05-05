/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:52:53 by cdupuis           #+#    #+#             */
/*   Updated: 2022/12/09 13:37:24 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*tab;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	tab = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tab)
		return (NULL);
	while (s1[++i] != '\0')
		tab[i] = s1[i];
	while (s2[j] != '\0')
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	free(s1);
	return (tab);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
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
	return (0);
}

char	*ft_strdup(char *source)
{
	int		i;
	char	*str;

	i = 0;
	if (!source)
		return (NULL);
	str = (char *)malloc(sizeof(char) * ft_strlen(source) + 1);
	if (!str)
		return (NULL);
	while (source[i] != '\0')
	{
		str[i] = source[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
