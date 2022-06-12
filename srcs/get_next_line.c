/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashitomi<ashitomi@student.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 08:06:24 by ashitomi          #+#    #+#             */
/*   Updated: 2022/04/16 19:40:17 by ashitomi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*ft_read(int fd, char *save)
{
	char	*tmp;
	int		read_rtn;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	read_rtn = 1;
	while (!ft_strchr_gnl(save, '\n') && read_rtn != 0)
	{
		read_rtn = read(fd, tmp, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_rtn] = '\0';
		save = ft_strjoin_gnl(save, tmp);
	}
	free(tmp);
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	rtn = (char *)malloc(sizeof(char) * (i + 2));
	if (!rtn)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		rtn[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		rtn[i] = '\n';
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_save(char *save)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	s = (char *)malloc((ft_strlen_gnl(save) - i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (save[i])
		s[c++] = save[i++];
	s[c] = '\0';
	free(save);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
