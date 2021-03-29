/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:32:17 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/24 15:33:14 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int check_updown(char *first, char *last)
{
    int i = 0;
    while (first[i])
    {
        if (first[i] != '1' && first[i] != ' ')
            return(-1);
        i++;
    }
    i = 0;
    while (last[i])
    {
        if (last[i] != '1' && last[i] != ' ')
            return(-1);
        i++;
    }
    return (1);
}

int check_edges(char **map, int y)
{
    int current;
    int previous;
    int x;

    x = 0;
    current = ft_strlen(map[y]) -1;
    previous = ft_strlen (map[y - 1]) - 1;
    if (current < previous)
    {
       //puts (map[y]);
        x = current + 1;
        while (map[y-1][x])
        {
            if (map[y-1][x] != '1' && map[y-1][x] != ' ')
            {
                printf("Map architecture problem [%c] row |%d| column |%d|\n", map[y - 1][x-1], y, x);
                return (-1);
            }
            x++;
        }
    }
    else if (current > previous)
    {
        x = previous + 1;
        while (map[y][x])
        {
            if (map[y][x] != '1' && map[y][x] != ' ')
            {
                printf("Map architecture problem [\"%c\"] row |%d| column |%d|\n", map[y][x-1], y + 1, x);
                return (-1);
            }
            x++;
        }
    }
    return (1);
}

int check_line(char **map, int y)
{
    int x = 0;
    char c;
    if (check_edges(map, y) == -1)
        return (-1);
    while (map[y][x])
    {
        c = map[y][x];
        if (c == 'W' || c == 'E' || c == 'S' || c == 'N')
            g_p.spawn++;
        if (c != '1' && c != 'W' && c != 'E' && c != 'S' && c != 'N' && c != '2' && c != '0' && c != ' ')
        {
            printf("Invalid character %c\n%s\n", c, map[y]);
            return (-1);
        }
        x++;
    }
    return (1);
}

int check_map(char **map)
{
    int i = 1;
    int len;
    if (check_updown(map[0], map[g_p.map_h]) == -1)
    {
        puts("Error in first or last row");
        return (-1);
    }
    while (i < g_p.map_h)
    {
        len = ft_strlen(map[i]) - 1;
        if ((map[i][0] != '1' || map[i][len] != '1') && (map[i][0] != ' ' || map[i][len] != ' '))
        {
            puts("Invalid borders");
            return (-1);
        }
        i++;
    }
    i = 1;
    while (i <= g_p.map_h)
    {
        if (check_line(map, i++) == -1)
          return (-1);
    }
    if (g_p.spawn != 1)
    {
        puts("Spawn is invalid");
        return (-1);
    }
   return (1);
}