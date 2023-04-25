/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:12:17 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/25 14:34:24 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				res;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	res = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (i < n)
	{
		if (*str1 != *str2)
		{
			return (res = *str1 - *str2);
		}
		i++;
		str1++;
		str2++;
	}
	return (res);
}
