/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:36:02 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/16 12:45:01 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main()
{
	char	**line;
	int		fd_map;
	int		i;

	fd_map = open("map.cub", O_RDONLY);
	i = get_next_line(fd_map, line);
	printf("\n|%s|\n", (*line));
	if(i == 1)
	{
		struct_init();
        ft_render(line);
	}
	printf("\n|Width : %d|\n", g_p.res_w);
	return (0);
}