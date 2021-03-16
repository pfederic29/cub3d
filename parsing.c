#include "cub3d.h"

//int parsing(t_parse *g_p)
//{
//    int fd;
//    char **line;
//    int i;
//
//    fd = open("map.cub", O_RDONLY);
//    i = get_next_line(fd, line);
//    if(i == 1)
//        ft_render(g_p, line);    
//}
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
}

void 	ft_render(char **line)
{
	int i;
	int	h;

	h = 0;
	printf("\n|Initial string char: %c|\n", *line[0]);
	if(*line[0] == 'R')
	{
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
	else
		write(1, "Error!\n", 7);   
	printf("\n|heigth: %d|\n", g_p.res_h);
	printf("\n|width: %d|\n", g_p.res_w);
}
