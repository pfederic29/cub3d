/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:28:34 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 11:36:39 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_parse(char **line, int fd)
{
	int		i;
	int		y;
	char	*newl;

	i = 1;
	y = 0;
	newl = ft_strjoin((*line), "X");
	while (i > 0)
	{
		i = get_next_line(fd, line);
		newl = ft_strjoin(newl, (*line));
		newl = ft_strjoin(newl, "X");
	}
	
	g_p.map = ft_split(newl, 'X');
	if (check_rows(newl) == -1 || check_map(g_p.map) == -1)
	{
		write(1, "Error\n", 6);
		g_check.err = -1;;
	}
	free(newl);
	return (g_check.err);
}

char	*wall_store(char **line)
{
	int		i;
	int		j;
	char	*nwline;

	i = 2;
	j = 0;
	while ((*line)[i] == ' ' && (*line)[i] != '.')
		i++;
	if ((*line)[i] == 0)
		return (0);
	else
	{
		if (!(nwline = malloc(ft_strlen(*line + i) + 1)))
			return (0);
		while ((*line)[i] && (*line)[i] != ' ')
			nwline[j++] = (*line)[i++];
		nwline[j] = 0;
		free(*line);
	}
	return (nwline);
}

char	*sfc_store(char **line)
{
	int		i;
	int		j;
	char	*nwline;

	i = 1;
	j = 0;
	while ((*line)[i] == ' ' && (*line)[i] != '.')
		i++;
	if ((*line)[i] == 0)
		return (0);
	else
	{
		if (!(nwline = malloc(ft_strlen(*line + i) + 1)))
			return (0);
		while ((*line)[i] && (*line)[i] != ' ')
			nwline[j++] = (*line)[i++];
		nwline[j] = 0;
		free(*line);
	}
	return (nwline);
}

int	sfc_tx(char **line, int j)
{
	if ((*line)[j] == 'S' && g_check.s == 0)
	{
		g_p.sfc[0] = sfc_store(line);
		g_check.s = 1;
	}
	else if ((*line)[j] == 'F'&& g_check.f == 0)
	{
		g_p.sfc[1] = sfc_store(line);
		g_check.f = 1;
	}
	else if ((*line)[j] == 'C' && g_check.c == 0)
	{
		g_p.sfc[2] = sfc_store(line);
		g_check.c = 1;
	}
	else
		g_check.err = -1;
	return (g_check.err);
}

int		parse_tx(char **line, int j)
{
	if ((*line)[j] == 'N' && (*line)[j + 1] == 'O' && g_check.no == 0)
	{
		g_p.wall[0] = wall_store(line);
		g_check.no = 1;
	}
	else if ((*line)[j] == 'S' && (*line)[j + 1] == 'O' && g_check.so == 0)
	{
		g_p.wall[1] = wall_store(line);
		g_check.so = 1;
	}
	else if ((*line)[j] == 'W' && (*line)[j + 1] == 'E' && g_check.we == 0)
	{
		g_p.wall[2] = wall_store(line);
		g_check.we = 1;
	}
	else if ((*line)[j] == 'E' && (*line)[j + 1] == 'A' && g_check.ea == 0)
	{
		g_p.wall[3] = wall_store(line);
		g_check.ea = 1;
	}
	else if ((*line)[1] == ' ')
		g_check.err = sfc_tx(line, j);
	else
		g_check.err = -1;
	return (g_check.err);
}
