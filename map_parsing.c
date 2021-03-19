/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 14:28:34 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/19 16:53:24 by lmarzano         ###   ########.fr       */
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
