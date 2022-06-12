/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:40:18 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:18 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*init_map(char *av, t_prog *mlx)
{
	t_vstock	vars;

	mlx->map = NULL;
	mlx->stock = NULL;
	vars.temp = NULL;
	mlx->fd = open(av, O_RDONLY);
	if (mlx->fd < 0)
	{
		sys_err(1);
		return (NULL);
	}
	mlx->map = build_map(&*mlx, &vars);
	close(mlx->fd);
	if (!check_map_err(&*mlx, &vars))
	{
		free(mlx->map);
		return (NULL);
	}
	return (mlx->map);
}

/*
static void	init_img(t_prog *mlx)
{
	size_t	n;

	n = 0;
	mlx->ipath[0] = "xpm/collectible.xpm";
	mlx->ipath[1] = "xpm/player.xpm";
	mlx->ipath[2] = "xpm/exit.xpm";
	mlx->ipath[3] = "xpm/floor.xpm";
	mlx->ipath[4] = "xpm/wall.xpm";
	while (n <= 4)
	{
		mlx->iptr[n] = mlx_xpm_file_to_image(mlx->ptr,
				mlx->ipath[n], &mlx->iwidth[n], &mlx->iheight[n]);
		n++;
	}
}
*/

static void	init_img(t_prog *mlx)
{
	size_t	n;

	n = 0;
	mlx->ipath[0] = "xpm/sl_girl.xpm";
	mlx->ipath[1] = "xpm/sl_penita.xpm";
	mlx->ipath[2] = "xpm/sl_house.xpm";
	mlx->ipath[3] = "xpm/sl_floor.xpm";
	mlx->ipath[4] = "xpm/sl_wall.xpm";
	while (n <= 4)
	{
		mlx->iptr[n] = mlx_xpm_file_to_image(mlx->ptr,
				mlx->ipath[n], &mlx->iwidth[n], &mlx->iheight[n]);
		n++;
	}
}


static void	init_tprog_mlx(t_prog *mlx)
{
	mlx->iloop = 0;
	mlx->xnb = 0;
	mlx->ynb = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->fd = 0;
}

int	main(int argc, char **argv)
{
	t_prog	mlx;

	init_tprog_mlx(&mlx);
	if (argc != 2)
		return (usr_err(1));
	mlx.map = init_map(argv[1], &mlx);
	if (!mlx.map)
		return (map_err(7, 0, 0, 0));
	mlx.ptr = mlx_init();
	init_img(&mlx);
	mlx.win = mlx_new_window(mlx.ptr, mlx.xnb * 32, mlx.ynb * 32, "so_long");
	game_loop(&mlx);
	mlx.iloop = mlx_loop(mlx.ptr);
	return (0);
}
