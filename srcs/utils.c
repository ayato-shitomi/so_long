/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:40:18 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:18 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_isnotcharset(char c, char *set)
{
	size_t	a;

	a = 0;
	while (set[a])
	{
		if (c != set[a])
			return (1);
		a++;
	}
	return (0);
}

int	int_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (-1);
	while (s[a])
	{
		if (s[a] == (char)c)
			return (a);
		a++;
	}
	if (s[a] == (char)c)
		return (a);
	return (-1);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

int	free_split_map(char **split_map)
{
	size_t	c;

	c = 0;
	while (split_map[c])
	{
		free(split_map[c]);
		c++;
	}
	free(split_map);
	return (0);
}
