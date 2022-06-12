/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:40:35 by ashitomi          #+#    #+#             */
/*   Updated: 2021/11/03 06:23:23 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *from, const char *srch, size_t len)
{
	size_t	c_from;
	size_t	c_srch;

	if (srch[0] == '\0')
		return ((char *)from);
	c_from = 0;
	while (from[c_from] && c_from < len)
	{
		c_srch = 0;
		while (srch[c_srch] && from[c_from + c_srch] == srch[c_srch] \
			&& c_from + c_srch < len)
			c_srch++;
		if (srch[c_srch] == '\0')
			return ((char *)&from[c_from]);
		c_from++;
	}
	return (NULL);
}
