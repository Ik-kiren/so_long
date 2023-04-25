/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:18:17 by cdupuis           #+#    #+#             */
/*   Updated: 2022/11/24 14:17:01 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	initd;

	i = ft_strlen(dst);
	j = 0;
	initd = ft_strlen(dst);
	if (initd < dstsize - 1 && dstsize > 0)
	{
		while (src[j] && j + initd < dstsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = 0;
	}
	if (initd >= dstsize)
		initd = dstsize;
	return (initd + ft_strlen(src));
}
