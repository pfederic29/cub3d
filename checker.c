/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:32:17 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/26 11:27:33 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_res(void)
{
	if (g_p.res_w > 2147483647 || g_p.res_h > 2147483647)
		g_check.err = -1;
	return (g_check.err);
}

int	check_val(void)
{
	g_check.err = check_res();
	return (g_check.err);
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
        if (newl[y] == 'X' && newl[y + 1] == 'X' && i < g_p.map_h)
            return (-1);
            y++;
    }
    return (1);
}