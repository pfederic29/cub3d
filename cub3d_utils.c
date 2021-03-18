/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 17:20:53 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/18 12:21:38 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

//char	**matrix_realloc(char **line, int j)
//{
//	char	**new;
//	int		i;
//
//	i = 0;
//	if (!(new = malloc(ft_strlen(line[i][j + 1]) * sizeof(char) + 1)))
//		return (NULL);
//	if (**line)
//	{
//		while (line[i][j])
//		{
//			new[i][j] = line[i][j];
//			i++;
//		}
//		free(line[i][j]);
//		*line = NULL;
//	}
//	new[i][j] = '\0';
//	new[0][j + 1] = '\0';
//	return (new);
//}

char	*ft_realloc(char **line)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(ft_strlen(*line) + BUFFER_SIZE + 1)))
		return (NULL);
	if (*line)
	{
		while ((*line)[i])
		{
			new[i] = (*line)[i];
			i++;
		}
		free(*line);
		*line = NULL;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_realloc_finale(char **line)
{
	char	*new;
	int		i;

	i = 0;
	if (!(new = malloc(ft_strlen(*line) + 1)))
		return (NULL);
	if (*line)
	{
		while ((*line)[i])
		{
			new[i] = (*line)[i];
			i++;
		}
		free(*line);
		*line = NULL;
	}
	new[i] = '\0';
	return (new);
}
