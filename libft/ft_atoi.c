/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:17:39 by ashitomi          #+#    #+#             */
/*   Updated: 2021/11/03 06:23:22 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_so_long_atoi(int bool_ng)
{
	if (bool_ng == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	int			bool_ng;
	int			i;
	long int	num;

	i = 0;
	bool_ng = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			bool_ng = bool_ng * -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
		if ('0' <= str[i] && str[i] <= '9'
			&& (num * 10 + (str[i] - 48)) / 10 != num && str[i])
			return (ft_so_long_atoi(bool_ng));
	}
	return (num * bool_ng);
}
