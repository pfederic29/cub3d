/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:28:34 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/17 18:33:29 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_parse(char **line, int j)
{
	int	i;

	i = 0;
	while (line[i][j])
	{
		if (j == 0 || !line[i][j + 1])
		{
			while (line[i][j] == ' ' || line[i][j] == '1')
			{
				(*g_p.map)[j] = matrix_realloc(line, j);
				i++;
			}
		}
	}
	printf("|%s\n|", g_p.map[j]);
	return (1);
}
