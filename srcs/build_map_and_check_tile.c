/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map_and_check_tile.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:40:17 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:17 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*build_map(t_prog *mlx, t_vstock *vars)
{
	while (!mlx->stock)
	{
		mlx->stock = get_next_line(mlx->fd);
		if (!mlx->stock || !mlx->stock[0])
		{
			free(mlx->stock);
			return (mlx->map);
		}
		if (!mlx->map)
			mlx->map = ft_substr(mlx->stock, 0, ft_strlen(mlx->stock));
		else
		{
			vars->temp = mlx->map;
			mlx->map = ft_strjoin(mlx->map, mlx->stock);
			free(vars->temp);
		}
		ft_free(&mlx->stock);
	}
	return (mlx->stock);
}

int	check_tile(t_prog *mlx, char tile)
{
	if (tile == 'E')
	{
		if (int_strchr(mlx->map, 'C') == -1)
		{
			close_window(&*mlx);
			return (0);
		}
		else
			return (usr_err(3));
	}
	else if (tile == '1')
		return (usr_err(4));
	return (1);
}
