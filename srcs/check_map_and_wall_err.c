/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_and_wall_err.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:40:17 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:17 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_wall_err(char *map)
{
	char	**split_map;
	size_t	a;
	size_t	len;

	a = 0;
	split_map = ft_split(map, '\n');
	len = ft_strlen(split_map[0]);
	if (ft_isnotcharset('1', split_map[0]))
		return (free_split_map(split_map) * map_err(3, 0, 0, 0));
	while (split_map[a])
	{
		if (ft_strlen(split_map[a]) != len)
			return (free_split_map(split_map) * map_err(4, 0, 0, 0));
		if (split_map[a][len - 1] != '1' || split_map[a][0] != '1')
			return (free_split_map(split_map) * map_err(5, 0, 0, 0));
		a++;
	}
	free_split_map(split_map);
	return (1);
}

int	check_map_err(t_prog *mlx, t_vstock *vars)
{
	int	a;

	a = 0;
	vars->pcount = 0;
	vars->ecount = 0;
	vars->ccount = 0;
	while (mlx->map[a++])
	{
		if (int_strchr(MAPSET, mlx->map[a]) == -1)
			return (map_err(1, 0, 0, 0));
		if (mlx->map[a] == 'P')
			vars->pcount++;
		if (mlx->map[a] == 'E')
			vars->ecount++;
		if (mlx->map[a] == 'C')
			vars->ccount++;
		if (mlx->map[a] == '\n' || mlx->map[a] == '\0')
			mlx->ynb++;
	}
	if (!check_wall_err(mlx->map)
		|| vars->pcount != 1 || vars->ecount < 1 || vars->ccount < 1)
		return (map_err(2, vars->pcount, vars->ecount, vars->ccount));
	mlx->xnb = int_strchr(mlx->map, '\n');
	mlx->ynb--;
	return (1);
}
