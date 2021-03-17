/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:36:05 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/17 12:04:12 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parsing(char **line)
{
	if ((*line)[0] == 'R')
		res_parse(line);
	else if ((*line)[0] == 'N')
	{
		if ((*line)[1] != 'O')
			return (-1);
		rgb_parse(line, g_p.n_wall);
		if (g_p.n_wall[0] > 256 || g_p.n_wall[1] > 256 || g_p.n_wall[2] > 256)
			return (-1);
	}
	else if ((*line)[0] == 'S' && (*line)[1] == 'O')
	{
		rgb_parse(line, g_p.s_wall);
		if (g_p.s_wall[0] > 256 || g_p.s_wall[1] > 256 || g_p.s_wall[2] > 256)
			return (-1);
	}
	else if ((*line)[0] == 'S' && (*line)[1] == ' ')
	{
		rgb_parse(line, g_p.sky);
		if (g_p.sky[0] > 256 || g_p.sky[1] > 256 || g_p.sky[2] > 256)
			return (-1);
	}
	else if ((*line)[0] == 'W')
	{
		if ((*line)[1] != 'E')
			return (-1);
		rgb_parse(line, g_p.w_wall);
		if (g_p.w_wall[0] > 256 || g_p.w_wall[1] > 256 || g_p.w_wall[2] > 256)
			return (-1);
	}
	else if ((*line)[0] == 'E')
	{
		if ((*line)[1] != 'A')
			return (-1);
		rgb_parse(line, g_p.e_wall);
		if (g_p.e_wall[0] > 256 || g_p.e_wall[1] > 256 || g_p.e_wall[2] > 256)
			return (-1);
	}
	else if ((*line)[0] == 'F')
	{
		if ((*line)[1] != ' ')
			return (-1);
		rgb_parse(line, g_p.floor);
		if (g_p.floor[0] > 256 || g_p.floor[1] > 256 || g_p.floor[2] > 256)
			return (-1);
	}
	else if ((*line)[0] == 'C')
	{
		if ((*line)[1] != ' ')
			return (-1);
		rgb_parse(line, g_p.ceiling);
		if (g_p.ceiling[0] > 256 || g_p.ceiling[1] > 256 || g_p.ceiling[2] > 256)
			return (-1);
	}
	else if ((*line)[1] == ' ' || (*line)[1] == '1')
	{
		return (1);
		//funzione di parsing della mappa
	}
	else if ((*line)[0] != '\n' || (*line)[0] != 0)
		return (-1);
	return (1);
}

void 	res_parse(char **line)
{
	int i;
	int	h;

	h = 0;
	i = 1;
	while (line[i])
	{
		while ((ft_isdigit((*line)[i]) == 1) || (*line)[i] == ' ')
		{
			if ((*line)[i] == ' ')
			{
				h = 1;
				break;
			}
			g_p.res_w = g_p.res_w * 10 + ((int)(*line)[i] - 48);
			i++;
		}
		i++;
		if (h == 1 && g_p.res_w != 0)
		{
			while (ft_isdigit((*line)[i]) == 1)
			{
				g_p.res_h = g_p.res_h * 10 + ((int)(*line)[i] - 48);
				i++;
			}
		}
	}
}

void	rgb_parse(char **line, int rgb[3])
{
	int i;
	int	h;

	h = 0;
	i = 1;
	while ((*line)[i])
	{
		while (ft_isdigit((*line)[i]) == 1)
		{
			rgb[h] = rgb[h] * 10 + ((int)(*line)[i] - 48);
			i++;
		}
		if ((*line)[i] == ',')
			h++;
		i++;
	}
}
