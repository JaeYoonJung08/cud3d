/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 01:57:25 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/13 17:47:50 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# define SUCCESS 0
# define FAIL 1

# define NO 2
# define SO 3
# define EA 4
# define WE 5

typedef struct s_img
{
	void	*img_no;
	char	*img_no_name;
	void	*img_so;
	char	*img_so_name;
	void	*img_we;
	char	*img_we_name;
	void	*img_ea;
	char	*img_ea_name;
	int		ceil[3];
	int		ceil_flag;
	int		floor[3];
	int		floor_flag;
}	t_img;

typedef struct s_game
{
	char		*map;
	char		**map_copy;
	int			height;
	int			width;
	int			player_count;
	int			fd;
	t_img		*img;
	void		*mlx;
	void		*mlx_win;
}	t_game;

//cud3d_check.map.c
void	check_map(t_game *game);

//cub3d_overlap.c
void	check_overlap(t_game *game);

//cub3d_check_wall.c
void	check_wall(char **map);
int		only_space(char *map);

//cub_3d_check_zero.c
void	check_zero(char **map);

//cub3d_direction.c
void	check_direction(char *line, t_game *game, int *count);

//cub3d_error_free.c
void	error(const char *tmp);
char	**char_two_free(char **word);

//cub3d_read_map.c
int		line_string_count(char *line);
void	read_map(t_game *game);

//cub3d_rgb.c
void	check_rgb(char *line, t_game *game, int *count);

//str/split.c
char	**split_string(char const *s, char c);

//str/str.c
int		str_length(char const *str);
int		str_n_compare(const char *str1, const char *str2, size_t n);
long	atoi_while(char *str);
int		int_atoi(char *str);

//str/str2.c
char	*no_new_line(char *line);
char	*copy_string(const char *string);

#endif