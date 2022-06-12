/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_move_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:40:18 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:18 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_move_count(int c)
{
	ft_putstr_fd("Move count : ", 1);
	ft_putnbr_fd(c, 1);
	ft_putstr_fd("\n", 1);
}
