/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 19:40:17 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:17 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	putstr_stdo(char *s)
{
	ft_putstr_fd(" ", 1);
	ft_putstr_fd(s, 1);
}

int	usr_err(int n)
{
	if (n == 1)
	{
		putstr_stdo("ERROR > Invalid argument.\n");
		putstr_stdo("	Usage: ./so_long <map.ber>\n");
	}
	else if (n == 2)
		putstr_stdo("The game is closed!\n");
	else if (n == 3)
		putstr_stdo("You can't leave without all collectible.\n");
	else if (n == 4)
		putstr_stdo("There is a wall.\n");
	else if (n == 5)
		putstr_stdo("The player can't move up!\n");
	else if (n == 6)
		putstr_stdo("The player can't move left!\n");
	else if (n == 7)
		putstr_stdo("The player can't move down!\n");
	else if (n == 8)
		putstr_stdo("The player can't move right!\n");
	return (0);
}

int	sys_err(int n)
{
	if (n == 1)
		putstr_stdo("ERROR > Couldn't open a map.\n'");
	return (0);
}

int	map_err(int n, int pcount, int ecount, int ccount)
{
	if (n == 1)
	{
		putstr_stdo("ERROR > Only 'C', 'P', 'E', '0', '1' and '\\n' ");
		putstr_stdo("are allowed in the map-file.\n");
	}
	else if (n == 2)
	{
		if (pcount < 1)
			putstr_stdo("ERROR > There isn't any Spawn point on the map.\n");
		if (pcount > 1)
			putstr_stdo("ERROR > There are too many SpawnPoint on the map.\n");
		if (ecount < 1)
			putstr_stdo("ERROR > There isn't any Exit point on the map.\n");
		if (ccount < 1)
			putstr_stdo("ERROR > There isn't any Collectible on the map.\n");
	}
	else
		map_err_two(n);
	return (0);
}

int	map_err_two(int	n)
{
	if (n == 3)
		putstr_stdo("ERROR > The map is not closed on its top.\n");
	else if (n == 4)
		putstr_stdo("ERROR > The map must be rectangulare.\n");
	else if (n == 5)
		putstr_stdo("ERROR > The map is not closed on its side.\n");
	else if (n == 6)
		putstr_stdo("ERROR > There is something wrong with the map :( \n");
	else if (n == 7)
		putstr_stdo("ERROR > The map is not playable.\n");
	return (0);
}
