/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/16 12:37:43 by lmarzano         ###   ########.fr       */
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
	int			res_w;
	int			res_h;
	short int	n_wall[3];
	short int	s_wall[3];
	short int	w_wall[3];
	short int	e_wall[3];
	short int	sky[3];
	short int	floor[3];
	short int	ceiling[3];
	char		map[1920][1080];
}				t_parse;
t_parse			g_p;
/*
** functions
*/
int				get_next_line(int fd, char **line);
int				just_do_it(char **line, char *buffer);

char			*ft_realloc(char **line);
char			*ft_realloc_finale(char **line);
/*
** utils
*/
size_t			ft_strlen(const char *s);
int				ft_isdigit(int c);
/*
** parsing
*/
void		struct_init(void);
void 			ft_render(char **line);

#endif
