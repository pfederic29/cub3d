/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:36:02 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 15:30:39 by lmarzano         ###   ########.fr       */
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
	g_check.mp = 0;
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
	g_p.n_wall[0] = -1;
	g_p.n_wall[1] = -1;
	g_p.n_wall[2] = -1;
	g_p.s_wall[0] = -1;
	g_p.s_wall[1] = -1;
	g_p.s_wall[2] = -1;
	g_p.w_wall[0] = -1;
	g_p.w_wall[1] = -1;
	g_p.w_wall[2] = -1;
	g_p.e_wall[0] = -1;
	g_p.e_wall[1] = -1;
	g_p.e_wall[2] = -1;
	g_p.sky[0] = -1;
	g_p.sky[1] = -1;
	g_p.sky[2] = -1;
	g_p.floor[0] = -1;
	g_p.floor[1] = -1;
	g_p.floor[2] = -1;
	g_p.ceiling[0] = -1;
	g_p.ceiling[1] = -1;
	g_p.ceiling[2] = -1;
	ref_init();
	check_init();
}

int		main(int argc, const char **argv)
{
	char	*line;
	int		fd_map;
	int		val;
	//int		q = 0;
	
	if (argc != 2 && argc != 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	fd_map = open(argv[1], O_RDONLY);
	val = 1;
	struct_init();
	while (val)
	{
		val = get_next_line(fd_map, &line);
		if (val == 1)
		{
			g_check.err = parsing(&line, fd_map);
		}
		else if (val == -1)
			write(1, "Error\n", 6);
	}
	g_check.err = check_val();
	if (g_check.err == -1)
				write(1, "Error\n", 6);
	//while (g_p.map[q] != 0)
	//{
	//	printf("%s\n", g_p.map[q]);
	//	q++;
	//}
	//printf ("C %d, %d, %d\n", g_p.ceiling[0], g_p.ceiling[1], g_p.ceiling[2]);
	//printf("|mp %d|\n|r %d|\n|no %d|\n|so %d|\n|we %d|\n|ea %d|\n|s %d|\n|f %d|\n|c %d|\n", g_check.mp, g_check.r, g_check.no, g_check.so, g_check.we, g_check.ea, g_check.s, g_check.f, g_check.c);
	return (0);
}
