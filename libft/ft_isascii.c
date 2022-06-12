/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:40:34 by ashitomi          #+#    #+#             */
/*   Updated: 2021/11/03 06:23:22 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

/*
#include <stdio.h>
int	main(void)
{
	for (int i = 0; i < 300; i++)
	{
		printf("%d %c > ", i, (char)i);
		if (ft_isascii(i) != 0)
			printf("ASCII\n");
		else
			printf("else\n");
	}
	return 0;
}
*/
