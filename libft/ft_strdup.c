/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:17:02 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/25 11:41:38 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(source) + 1);
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
