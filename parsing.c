#include "cub3d.h"

int parsing(t_parse *g_p)
{
    int fd;
    char **line;
    int i;

    fd = open("map.cub", O_RDONLY);
    i = get_next_line(fd, line);
    if(i == 1)
    ft_render(g_p, line);    
}

void ft_render(t_parse *g_p, char **line)
{
    int i;

    i = 0;
    
    
   // printf("%c", (*line)[i]);
    if((*line)[i] == 'R')
    {
        i++;
        g_p->res_w = 0;
        while((*line)[i] == ' ')
            i++;
        
        while (ft_isdigit((*line)[i]))
        {
            g_p->res_w = g_p->res_w * 10 + ((int)(*line)[i] - 48);
            i++;
        }
    }

    printf("%i", g_p->res_w);     
}

int main()
{
    t_parse *g_p;
    parsing(g_p);
    return(0);
}