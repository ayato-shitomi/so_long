/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:40:10 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:10 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*/////////////////////////////////////////
	DEFINES
/*/////////////////////////////////////////

# define MAPSET "CPE01\n"

/*/////////////////////////////////////////
	INCLUDES
/*/////////////////////////////////////////

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "key.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "get_next_line.h"
# include <X11/Xlib.h>
# include <X11/Xutil.h>

/*/////////////////////////////////////////
	TYPEDEFS
/*/////////////////////////////////////////

/*
void	*ptr			mlx init pointer			mlx_init
void	*win			window pointer				mlx_new_window
int		iloop			loop num
void	*iptr[5]		xpm file image pointer		mlx_xpm_file_to_image
char	*ipath[5]		path of the xpm file
int		iwidth[5]		width of the xpm file		mlx_xpm_file_to_image
int		iwidth[5]		height of the xpm file		mlx_xpm_file_to_image
char	*map			the map
int		xnb				size of a line
int		ynb				number of lines
int		x				x coordinate
int		y				y coordinate
char	*stock			GNL output for map
int		fd				FD of the map for GNL
*/

typedef struct s_program
{
	void	*ptr;
	void	*win;
	int		iloop;
	void	*iptr[5];
	char	*ipath[5];
	int		iwidth[5];
	int		iheight[5];
	char	*map;
	int		xnb;
	int		ynb;
	int		x;
	int		y;
	char	*stock;
	int		fd;
}	t_prog;

/*
char	*temp		to free GNL output
int		pcount		char 'Player' count on map	need only 1
int		ecount		char 'E' count on map			need at least 1
int		ccount		char 'C' count on map			need at least 1
*/

typedef struct s_vstock
{
	char	*temp;
	int		pcount;
	int		ecount;
	int		ccount;
}	t_vstock;

/*/////////////////////////////////////////
	PROTOTYPES
/*/////////////////////////////////////////

//err.c
int		usr_err(int n);
int		sys_err(int n);
int		map_err(int n, int pcount, int ecount, int ccount);
int		map_err_two(int	n);

//check_map_and_wall_err.c
int		check_wall_err(char *map);
int		check_map_err(t_prog *mlx, t_vstock *vars);

//utils.c
int		ft_isnotcharset(char c, char *set);
int		int_strchr(const char *s, int c);
void	ft_free(char **str);
int		free_split_map(char **split_map);

//game_loop.c
void	game_loop(t_prog *mlx);
int		close_window(t_prog *mlx);

//build_map_and_check_tile.c
char	*build_map(t_prog *mlx, t_vstock *vars);
int		check_tile(t_prog *mlx, char tile);

//print_move_count.c
void	print_move_count(int c);

#endif
