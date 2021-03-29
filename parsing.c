/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:36:05 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/29 10:12:48 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_sfc(char **line)
{
	if ((*line)[0] == 'S')
	{
		rgb_parse(line, g_p.sky);
		if (g_p.sky[0] > 255 || g_p.sky[1] > 255 || g_p.sky[2] > 255)
			return (-1);
	}
	else if ((*line)[0] == 'F')
	{
		rgb_parse(line, g_p.floor);
		if (g_p.floor[0] > 255 || g_p.floor[1] > 255 || g_p.floor[2] > 255)
			return (-1);
	}
	else if ((*line)[0] == 'C')
	{
		rgb_parse(line, g_p.ceiling);
		if (g_p.ceiling[0] > 255 || \
		g_p.ceiling[1] > 255 || g_p.ceiling[2] > 255)
			return (-1);
	}
	else
		return (-1);
	return (1);
}

int		parse_wall(char **line)
{
	if ((*line)[0] == 'N' && (*line)[1] == 'O')
	{
		rgb_parse(line, g_p.n_wall);
		return ((g_p.n_wall[0] > 255 || g_p.n_wall[1] > 255 ||\
		g_p.n_wall[2] > 255) ? -1 : 1);
	}
	else if ((*line)[0] == 'S' && (*line)[1] == 'O')
	{
		rgb_parse(line, g_p.s_wall);
		return ((g_p.s_wall[0] > 255 || g_p.s_wall[1] > 255 ||\
		g_p.s_wall[2] > 255) ? -1 : 1);
	}
	else if ((*line)[0] == 'W' && (*line)[1] == 'E')
	{
		rgb_parse(line, g_p.w_wall);
		return ((g_p.w_wall[0] > 255 || g_p.w_wall[1] > 255 ||\
		g_p.w_wall[2] > 255) ? -1 : 1);
	}
	else if ((*line)[0] == 'E' && (*line)[1] == 'A')
	{
		rgb_parse(line, g_p.e_wall);
		return ((g_p.e_wall[0] > 255 || g_p.e_wall[1] > 255 ||\
		g_p.e_wall[2] > 255) ? -1 : 1);
	}
	return (-1);
}

int		res_parse(char **line)
{
	int i;
	
	i = 1;
	while ((*line)[i])
	{
		while ((*line)[i] == ' ')
			i++;
		while (ft_isdigit((*line)[i]))
		{
			g_p.res_w = g_p.res_w * 10 + ((int)(*line)[i] - 48);
			i++;
		}
		while ((*line)[i] == ' ')
			i++;
		while (ft_isdigit((*line)[i]) == 1)
		{
			g_p.res_h = g_p.res_h * 10 + ((int)(*line)[i] - 48);
			i++;
		}
		while ((*line)[i] == ' ')
			i++;
		if ((*line)[i++])
			g_check.err = -1;
	}
	return (g_check.err);
}

void	rgb_parse(char **line, int rgb[3])
{
	int i;
	int	h;

	h = 0;
	i = 1;
	while ((*line)[i])
	{
		while (ft_isdigit((*line)[i]))
		{
			rgb[h] = rgb[h] * 10 + ((int)(*line)[i] - 48);
			i++;
		}
		if ((*line)[i] == ',')
			h++;
		i++;
	}
}

int		parsing(char **line, int fd)
{
	int	ret;
	int	i;

	ret = -1;
	i = 1;
	if (ft_isdigit((*line)[0]) == 0 || (*line)[0] == '1')
	{
		if ((*line)[0] == 'R')
			ret = res_parse(line);
		else if (((*line)[0] == 'S' && (*line)[1] == ' ') || (*line)[0] == 'F' || (*line)[0] == 'C')
		{
			while ((*line)[i] == ' ')
				i++;
			ret = (ft_isdigit((*line)[i]) == 1 ? parse_sfc(line) : sfc_tx(line));
		}
		else if ((*line)[0] == 'N' || (*line)[0] == 'S' || (*line)[0] == 'W' || (*line)[0] == 'E')
		{
			i = 2;
			while ((*line)[i] == ' ')
				i++;
			ret = (ft_isdigit((*line)[i]) == 1 ? parse_wall(line) : parse_tx(line));
		}
		else if ((*line)[0] == ' ' || (*line)[0] == '1')
			return (map_parse(line, fd));
		else if (!*line[0])
			return (1);
		else
			return (-1);
	}
	//ret = check_val();
	return (ret);
}
