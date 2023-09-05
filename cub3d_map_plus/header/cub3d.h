/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 01:57:25 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/05 04:52:29 by jaeyojun         ###   ########seoul.kr  */
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
	void	*img_so;
	void	*img_we;
	void	*img_ea;
	int		ceil[3];
	int		floor[3];
}	t_img;

typedef struct s_game
{
	char	*map;
	int		height;
	int		width;
	int		player_count;
	int		fd;
	t_img	*img;
	void	*mlx;
	void	*mlx_win;
}	t_game;

char	*no_new_line(char *line);

//cub3d_direction.c
void	put_img(int *count, t_game *game, char *temp, int flag);
void	check_direction(char *line, t_game *game, int *count);

//cub3d_error_free.c
void	error(const char *tmp);
char	**char_two_free(char **word);

//cub3d_read_map.c
int		line_string_count(char *line);
int		check_line(char *line, int line_len, t_game *game);
void	read_map(t_game *game);

//cub3d_rgb.c
void	check_rgb_invalid(char *temp);
void	check_color(char **temp_split, int *array);
void	input_rgb(char *temp, int *count, int *array);
void	check_rgb(char *line, t_game *game, int *count);

//cub3d.c
void	init_game(t_game *game, char *file);
int		check_argv(char *argv);

//str/split.c
char	**split_string(char const *s, char c);

//str/str.c
int		str_length(char const *str);
int		str_n_compare(const char *str1, const char *str2, size_t n);
long	atoi_while(char *str);
int		int_atoi(char *str);
#endif