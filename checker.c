/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:32:17 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/30 13:36:39 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_res(void)
{
	if (g_p.res_w > 2147483647 || g_p.res_h > 2147483647)
		return (-1);
    else if (g_p.res_w < g_p.res_h)
        return (-1);
	return (1);
}

int check_args(void)
{
    if (g_check.mp != 1 || g_check.r != 1 || g_check.no != 1 || g_check.so != 1 || g_check.we != 1 ||\
    g_check.ea != 1 || g_check.s != 1 || g_check.f != 1 || g_check.c != 1)
        return (-1);
    return (1);
}

int check_rgb(void)
{
    if (g_check.s == -1 || g_check.f == -1 || g_check.c == -1 ||\
    g_check.no == -1 || g_check.so == -1 || g_check.we == -1 || g_check.ea == -1)
        return (-1);
    return (1);
}

int	check_val(void)
{
    int i;

    i = 1;
	i = check_res();
    i = check_rgb();
    i = check_args();
	return (i);
}

int check_rows(char *newl)
{
    int y;
    int i;
    y = 0;
    i = 0;
    while (newl[y])
    {
        if (newl[y] == 'X')
            i++;
        if (newl[y] == 'X' && newl[y + 1] == 'X' && i < g_p.map_h + 1)
            return (-1);
            y++;
    }
    return (1);
}