/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/18 13:13:30 by lmarzano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
** structure
*/
typedef	struct	s_parse
{
	int		res_w;
	int		res_h;
	int		n_wall[3];
	int		s_wall[3];
	int		w_wall[3];
	int		e_wall[3];
	int		sky[3];
	int		floor[3];
	int		ceiling[3];
	char	**map;
	char	reference[8];
}				t_parse;
t_parse			g_p;
/*
** functions
*/
int				get_next_line(int fd, char **line);
int				just_do_it(char **line, char *buffer);

char			**matrix_realloc(char **line, int j);
char			*ft_realloc(char **line);
char			*ft_realloc_finale(char **line);
/*
** utils
*/
size_t			ft_strlen(char *s);
int				ft_isdigit(int c);
/*
** parsing
*/
int				parsing(char **line, int j);
int			res_parse(char **line);
void			rgb_parse(char **line, int rgb[3]);
/*
** map_parsing
*/
int				map_parse(char **line, int j);

#endif
