/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:40:17 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:17 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	close_window(t_prog *mlx)
{
	size_t	a;

	a = 0;
	mlx_clear_window(mlx->ptr, mlx->win);
	mlx_destroy_window(mlx->ptr, mlx->win);
	while (a <= 4)
	{
		mlx_destroy_image(mlx->ptr, mlx->iptr[a]);
		mlx->iptr[a] = NULL;
		a++;
	}
	mlx->ptr = NULL;
	mlx->win = NULL;
	a = usr_err(2);
	exit(mlx->iloop);
	return (1);
}

static int	check_dest(int	key, t_prog *mlx)
{
	int	p;

	p = int_strchr(mlx->map, 'P');
	if (key == K_W || key == K_UP)
	{
		if (!check_tile(&*mlx, mlx->map[p - mlx->xnb - 1]))
			return (usr_err(5));
	}
	else if (key == K_A || key == K_LEFT)
	{
		if (!check_tile(&*mlx, mlx->map[p - 1]))
			return (usr_err(6));
	}
	else if (key == K_S || key == K_DOWN)
	{
		if (!check_tile(&*mlx, mlx->map[p + mlx->xnb + 1]))
			return (usr_err(7));
	}
	else if (key == K_D || key == K_RIGHT)
	{
		if (!check_tile(&*mlx, mlx->map[p + 1]))
			return (usr_err(8));
	}
	return (p);
}

static int	display_map(t_prog mlx)
{
	int	a;
	int	i;

	a = 0;
	mlx.ynb = 0;
	while (mlx.map[a])
	{
		i = int_strchr(MAPSET, mlx.map[a]);
		if (i == 1)
			mlx_put_image_to_window(
				mlx.ptr, mlx.win, mlx.iptr[3], mlx.x * 32, mlx.y * 32);
		if (i >= 0 && i < 5)
			mlx_put_image_to_window(
				mlx.ptr, mlx.win, mlx.iptr[i], mlx.x++ *32, mlx.y * 32);
		else if (i == 5)
		{
			mlx.xnb = mlx.x;
			mlx.x = 0;
			mlx.y++;
		}
		a++;
	}
	return (0);
}

static int	hub_keypress(int key, t_prog *mlx)
{
	static int	count_move;
	int			p;

	p = check_dest(key, &*mlx);
	if (p == 0)
		return (0);
	if (key == K_W || key == K_UP || key == K_A || key == K_LEFT
		|| key == K_S || key == K_DOWN || key == K_D || key == K_RIGHT)
	{
		mlx->map[p] = '0';
		if (key == K_W || key == K_UP)
			mlx->map[p - mlx->xnb - 1] = 'P';
		else if (key == K_A || key == K_LEFT)
			mlx->map[p - 1] = 'P';
		else if (key == K_S || key == K_DOWN)
			mlx->map[p + mlx->xnb + 1] = 'P';
		else if (key == K_D || key == K_RIGHT)
			mlx->map[p + 1] = 'P';
		print_move_count(++count_move);
		mlx_clear_window(mlx->ptr, mlx->win);
		display_map(*mlx);
	}
	if (key == K_ESC)
		close_window(&*mlx);
	return (1);
}

void	game_loop(t_prog *mlx)
{
	display_map(*mlx);
	mlx_hook(mlx->win, 2, 1L << 0, hub_keypress, &*mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, &*mlx);
}
