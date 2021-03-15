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

void ft_render(char **line)
{
	int i;

	i = 0;
	
	while (line)
	{
		if((*line)[i] == 'R')
		{
			i++;
			g_p->res_w = 0;
			while (line)
			{
				while (ft_isdigit((*line)[i]))
				{
					g_p->res_w *= 10 + ((int)(*line)[i] - 48);
					i++;
				}
				i++;
			}
		}
		else
			write(1, "Error!\n", 7);
	}
	printf("\n|Width : %d|\n", g_p->res_w);     
}
