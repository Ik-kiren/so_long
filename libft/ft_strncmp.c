/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:21:28 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/25 16:22:17 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	res = 0;
	while (i < n)
	{
		if (str1[i] != str2[i] || str1[i] == 0 || str2[i] == 0)
		{
			res = str1[i] - str2[i];
			return (res);
		}
		i++;
	}
	return (0);
}
