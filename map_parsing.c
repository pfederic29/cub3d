/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:28:34 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/25 12:30:32 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_parse(char **line, int j, int fd)
{
	int		i;
	int		y;
	char	*newl;

	i = 0;
	y = 0;
	newl = ft_strjoin((*line), "X");
	while (1)
	{
		i = get_next_line(fd, line);
		newl = ft_strjoin(newl, (*line));
		newl = ft_strjoin(newl, "X");
		if (i <= 0)
			break ;
	}
	while (newl[y])
	{
		if (newl[y] == 'X')
			g_p.map_h++;
		y++;
	}
	g_p.map = ft_split(newl, 'X');
	free(newl);
	return (g_check.err);
}

char	*w_tx(char **line)
{
	int		i;
	int		j;
	char	*nwline;

	i = 0;
	j = 0;
	while ((*line)[i] != '.')
		i++;
	if ((*line)[i] == 0)
		return (0);
	else
	{
		if (!(nwline = malloc(ft_strlen(*line + i) + 1)))
			return (0);
		while ((*line)[i])
			nwline[j++] = (*line)[i++];
		nwline[j] = 0;
		free(*line);
	}
	return (nwline);
}

int	sfc_tx(char **line)
{
	if ((*line)[0] == 'S' && g_check.s == 0)
	{
		g_p.sfc[0] = w_tx(line);
		g_check.s = 1;
	}
	else if ((*line)[0] == 'F'&& g_check.f == 0)
	{
		g_p.sfc[1] = w_tx(line);
		g_check.f = 1;
	}
	else if ((*line)[0] == 'C' && g_check.c == 0)
	{
		g_p.sfc[2] = w_tx(line);
		g_check.c = 1;
	}
	else
		g_check.err = -1;
	return (g_check.err);
}

int		parse_tx(char **line)
{
	if ((*line)[0] == 'N' && (*line)[1] == 'O' && g_check.no == 0)
	{
		g_p.wall[0] = w_tx(line);
		g_check.no = 1;
	}
	else if ((*line)[0] == 'S' && (*line)[1] == 'O' && g_check.so == 0)
	{
		g_p.wall[1] = w_tx(line);
		g_check.so = 1;
	}
	else if ((*line)[0] == 'W' && (*line)[1] == 'E' && g_check.we == 0)
	{
		g_p.wall[2] = w_tx(line);
		g_check.we = 1;
	}
	else if ((*line)[0] == 'E' && (*line)[1] == 'A' && g_check.ea == 0)
	{
		g_p.wall[3] = w_tx(line);
		g_check.ea = 1;
	}
	else if ((*line)[1] == ' ')
		g_check.err = sfc_tx(line);
	else
		g_check.err = -1;
	return (g_check.err);
}
