/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:40:35 by ashitomi          #+#    #+#             */
/*   Updated: 2021/11/03 06:23:23 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*result;
	size_t	i;

	result = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	return (result);
}
