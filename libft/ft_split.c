/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:48:41 by ashitomi          #+#    #+#             */
/*   Updated: 2021/11/03 06:23:23 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_str(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

char	**ft_freeall(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}

char	**ft_loop(char const *s, char c, char **split, size_t len)
{
	size_t		index;
	const char	*start;

	index = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		while (*s != c && *s)
		{
			s++;
			len++;
		}
		if (*(s - 1) != c)
		{
			split[index++] = ft_substr(start, 0, len);
			if (split[index - 1] == NULL)
				return (ft_freeall(split));
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len;

	len = 0;
	split = (char **)ft_calloc(((ft_count_str(s, c)) + 1), sizeof(*split));
	if (!split)
		return (0);
	return (ft_loop(s, c, split, len));
}
