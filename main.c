/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:36:02 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/29 14:03:45 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_init(void)
{
	g_check.r = 0;
	g_check.no = 0;
	g_check.so = 0;
	g_check.we = 0;
	g_check.ea = 0;
	g_check.s = 0;
	g_check.f = 0;
	g_check.c = 0;
	g_check.err = 1;
	
}

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
	g_p.map_h = -1;
	g_p.spawn = 0;
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
	check_init();
}

int		main(int argc, const char **argv)
{
	char	*line;
	int		fd_map;
	int		val;
	int	q = 0;

	//if (argc != 2 && argc != 3)
	//{
	//	write(1, "Error\n", 6);
	//	return (0);
	//}
	fd_map = open("map.cub", O_RDONLY);
	val = 1;
	struct_init();
	while (val)
	{
		val = get_next_line(fd_map, &line);
		if (val == 1)
		{
			g_check.err = parsing(&line, fd_map);
			if (g_check.err == -1)
				write(1, "Error\n", 6);
		}
		else if (val == -1)
			write(1, "Error\n", 6);
	}
/*
** DEBUG : controllo parsing
	printf("\n|W : %d| |H : %d|\n", g_p.res_w, g_p.res_h);
	printf("\nAllowed Chars in Map: |%s|\n", g_p.reference);
	printf("\n|Map Heigth: %d|\n", g_p.map_h);
	printf("|debug:\nN:|%d, %d, %d|\nS:|%s|\nW:|%s|\nE:|%s|\n", g_p.n_wall[0], g_p.n_wall[1], g_p.n_wall[2], g_p.wall[1], g_p.wall[2], g_p.wall[3]);
	printf("debug:\n|S:|%s|\n", g_p.sfc[0]);
	printf("|F:|%d||%d||%d|\n", g_p.floor[0], g_p.floor[1], g_p.floor[2]);
	printf("|C:|%d||%d||%d|\n", g_p.ceiling[0], g_p.ceiling[1], g_p.ceiling[2]);
*/
	while (g_p.map[q] != 0)
	{
		printf("%s\n", g_p.map[q]);
		q++;
	}
	return (0);
}
