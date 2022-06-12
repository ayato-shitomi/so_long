/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:40:35 by ashitomi          #+#    #+#             */
/*   Updated: 2021/11/03 06:23:22 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			cnt;
	char			*too;
	const char		*frm;

	frm = (const char *)src;
	too = (char *)dst;
	cnt = 0;
	if (frm == NULL && too == NULL)
		return (NULL);
	while (cnt < n)
	{
		too[cnt] = frm[cnt];
		cnt++;
	}
	return (dst);
}
