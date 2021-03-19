/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:36:02 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/19 16:43:25 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ref_init(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	g_p.reference[0] = ' ';
	g_p.reference[1] = '0';
	g_p.reference[2] = '1';
	g_p.reference[3] = '2';
	g_p.reference[4] = 'N';
	g_p.reference[5] = 'S';
	g_p.reference[6] = 'E';
	g_p.reference[7] = 'W';
}

void	struct_init(void)
{
	g_p.res_w = 0;
	g_p.res_h = 0;
	g_p.n_wall[0] = 0;
	g_p.n_wall[1] = 0;
	g_p.n_wall[2] = 0;
	g_p.s_wall[0] = 0;
	g_p.s_wall[1] = 0;
	g_p.s_wall[2] = 0;
	g_p.w_wall[0] = 0;
	g_p.w_wall[1] = 0;
	g_p.w_wall[2] = 0;
	g_p.e_wall[0] = 0;
	g_p.e_wall[1] = 0;
	g_p.e_wall[2] = 0;
	g_p.sky[0] = 0;
	g_p.sky[1] = 0;
	g_p.sky[2] = 0;
	g_p.floor[0] = 0;
	g_p.floor[1] = 0;
	g_p.floor[2] = 0;
	g_p.ceiling[0] = 0;
	g_p.ceiling[1] = 0;
	g_p.ceiling[2] = 0;
	ref_init();
}

int	main(void)
{
	char	**line;
	int		fd_map;
	int		i;
	int		j;
	int	q = 0;
	int		rd;

	fd_map = open("map.cub", O_RDONLY);
	i = 1;
	j = -1;
	struct_init();
	while (i)
	{
		i = get_next_line(fd_map, line);
		if (i == 1)
			i = parsing(line, j, fd_map);
		else if (i == -1)
			write(1, "Error!\n", 7);
	}
/*
** DEBUG : controllo parsing
*/
	printf("\nAllowed Chars in Map: |%s|\n", g_p.reference);
	printf("\n|width: %d|\n", g_p.res_w);
	printf("|heigth: %d|\n", g_p.res_h);
	printf("|NO: %d, %d, %d|\n", g_p.n_wall[0], g_p.n_wall[1], g_p.n_wall[2]);
	printf("|SO: %d, %d, %d|\n", g_p.s_wall[0], g_p.s_wall[1], g_p.s_wall[2]);
	printf("|WE: %d, %d, %d|\n", g_p.w_wall[0], g_p.w_wall[1], g_p.w_wall[2]);
	printf("|EA: %d, %d, %d|\n", g_p.e_wall[0], g_p.e_wall[1], g_p.e_wall[2]);
	printf("|S: %d, %d, %d|\n", g_p.sky[0], g_p.sky[1], g_p.sky[2]);
	printf("|F: %d, %d, %d|\n", g_p.floor[0], g_p.floor[1], g_p.floor[2]);
	printf("|C: %d, %d, %d|\n\n", g_p.ceiling[0], g_p.ceiling[1], g_p.ceiling[2]);
	while (g_p.map[q] != 0)
	{
		printf("|%s|\n", g_p.map[q]);
		q++;
	}
	return (0);
}
