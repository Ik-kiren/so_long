/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdupuis <cdupuis@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:20:53 by cdupuis           #+#    #+#             */
/*   Updated: 2023/03/23 13:20:22 by cdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(int argc, char **argv)
{
	char	*p;

	p = 'c';
	ft_printf(" %x %X \n", 450, 9999);
	printf(" %x %X\n", 450, 9999);
	ft_printf(" %X \n", 4780);
	printf(" %X \n", 4780);
	ft_printf(" %c \n", '0' - 256);
	printf(" %c \n", '0' - 256);
	ft_printf("%c%c%c \n", 'a', '\t', 'b');
	printf("%c%c%c  \n", 'a', '\t', 'b');
	ft_printf("%d\n", INT_MAX);
	printf("%d\n", INT_MAX);
	ft_printf("%d\n", INT_MIN);
	printf("%d\n", INT_MIN);
	ft_printf("%p\n", p);
	printf("%p\n", p);
}
