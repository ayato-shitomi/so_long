/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 23:40:35 by ashitomi          #+#    #+#             */
/*   Updated: 2021/11/03 06:23:23 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_strchr((char *)set, s1[i]) != NULL)
		i++;
	len = ft_strlen(&s1[i]);
	if (len != 0)
	{
		while (s1[i + len - 1] && \
			ft_strchr((char *)set, s1[i + len - 1]) != NULL)
			len--;
	}
	new_str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, &s1[i], len);
	return (new_str);
}
