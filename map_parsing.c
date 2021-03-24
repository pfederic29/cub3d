/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:28:34 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/24 15:09:54 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_parse(char **line, int j, int fd)
{
	int		i;
	char	*newl;

	i = 0;
	newl = ft_strjoin((*line), "F");
	while (1)
	{
		i = get_next_line(fd, line);
		newl = ft_strjoin(newl, (*line));
		newl = ft_strjoin(newl, "F");
		if (i <= 0)
			break ;
	}
	g_p.map = ft_split(newl, 'F');
	free(newl);
	return (1);
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

int		parse_tx(char **line)
{
	if ((*line)[0] == 'N' && (*line)[1] == 'O')
		g_p.wall[0] = w_tx(line);
	else if ((*line)[0] == 'S' && (*line)[1] == 'O')
		g_p.wall[1] = w_tx(line);
	else if ((*line)[0] == 'W' && (*line)[1] == 'E')
		g_p.wall[2] = w_tx(line);
	else if ((*line)[0] == 'E' && (*line)[1] == 'A')
		g_p.wall[3] = w_tx(line);
	printf("|debug:\nN:|%s|\nS:|%s|\nW:|%s|\nE:|%s|\n", g_p.wall[0], g_p.wall[1], g_p.wall[2], g_p.wall[3]);
	return (1);
}
