/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarzano <lmarzano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 10:46:55 by lmarzano          #+#    #+#             */
/*   Updated: 2021/03/26 11:27:52 by lmarzano         ###   ########.fr       */
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
	char	*wall[4];
	char	*sfc[3];
	char	**map;
	char	reference[8];
	int		map_h;
}				t_parse;
t_parse			g_p;

typedef struct	s_checker
{
	int		r;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
	int		err;
}				t_checker;
t_checker		g_check;
/*
** functions
*/
int				get_next_line(int fd, char **line);
int				just_do_it(char **line, char *buffer);
/*
** utils [FULL]
*/
int				ft_isdigit(int c);
size_t			ft_strlen(char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_realloc(char **line);
char			*ft_realloc_finale(char **line);
/*
** utils_2 [FULL]
*/
size_t			ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t			ft_strcount(char *str, char c);
size_t			ft_strclen(char *s, char c);
char			**ft_split(char *s, char c);
size_t			ft_strlcat(char *dst, char *src, size_t dstsize);
/*
** parsing [FULL]
*/
int				parsing(char **line, int fd);
int				res_parse(char **line);
void			rgb_parse(char **line, int rgb[3]);
int				parse_wall(char **line);
int				parse_sfc(char **line);
/*
** map_parsing
*/
int				map_parse(char **line, int fd);
int				parse_tx(char **line);
/*
** checker
*/
int				check_val(void);
int				check_res(void);
int 			check_rows(char *newl);
#endif
