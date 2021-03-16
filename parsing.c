/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:36:05 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/16 17:57:16 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int parsing(char **line)
{
	if (*line[0] == 'R')
		res_parse(line);
	else if (*line[0] == 'N')
	{
		if ((*line)[1] != 'O')
			return (-1);
		nwall_parse(line);
	}
	//else if (*line[0] != '\n')
	//	return (-1);
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

void	nwall_parse(char **line)
{
	int i;
	int	h;

	h = 0;
	i = 1;
	while ((*line)[i])
	{
		printf("\n|current i: %c|\n", (*line)[i]);
		while (ft_isdigit((*line)[i]) == 1)
		{
			g_p.n_wall[h] = g_p.n_wall[h] * 10 + ((int)(*line)[i] - 48);
			printf("\n|debug NO: %d|\n", g_p.n_wall[h]);
			i++;
		}
		if ((*line)[i] == ',')
			h++;
		i++;
	}
}
