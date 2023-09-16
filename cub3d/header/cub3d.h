/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 01:57:25 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 17:56:12 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

# define SUCCESS	0
# define FAIL		1

# define X_BUTTON	17
# define X_EVENT_KEY_PRESS	2
# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_RIGHT	124
# define KEY_LEFT	123

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

# define WALL_X		0
# define WALL_Y		1

# define MOVE_SPEED	0.05
# define ROT_SPEED	0.05

typedef enum e_arrow
{
	FRONT,
	BACK,
	LEFT,
	RIGHT
}	t_arrow;

typedef enum e_dir
{
	NO,
	SO,
	WE,
	EA
}	t_dir;

typedef struct s_color
{
	int				ceil[3];
	unsigned int	c_color;
	int				ceil_flag;
	int				floor[3];
	unsigned int	f_color;
	int				floor_flag;
}	t_color;

typedef struct s_img
{
	void	*img;
	char	*path;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_ray
{
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	double	distance_x;
	double	distance_y;
	double	delta_x;
	double	delta_y;
	double	perp_wall;
	int		intpos_x;
	int		intpos_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		wall_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_render
{
	double	side_x;
	double	text_pos;
	double	text_step;
	int		text_num;
	int		text_x;
	int		text_y;
	int		color;
}	t_render;

typedef struct s_game
{
	t_player	*player;
	t_img		*img;
	t_img		text[4];
	t_color		*color;
	void		*mlx;
	void		*win;
	int			**buf;
	char		*map;
	char		**map_2d;
	int			height;
	int			player_count;
	int			fd;
}	t_game;

void	check_map(t_game *game);
void	check_overlap(t_game *game);
void	check_wall(char **map);
int		only_space(char *map);
void	check_zero(char **map);
void	check_direction(char *line, t_game *game, int *count);
void	error(const char *tmp);
char	**char_two_free(char **word);
int		line_string_count(char *line);
void	read_map(t_game *game);
void	check_rgb(char *line, t_game *game, int *count);
void	init_rgb(t_game *game);
char	**split_string(char const *s, char c);
int		str_length(char const *str);
int		str_n_compare(const char *str1, const char *str2, size_t n);
long	atoi_while(char *str);
int		int_atoi(char *str);
char	*no_new_line(char *line);
char	*copy_string(const char *string);
void	set_dda(t_game *game, t_ray *ray, int x);
void	run_dda(t_game *game, t_ray *ray);
void	calculate_wall(t_game *game, t_ray *ray);
void	set_render(t_game *game, t_ray *ray, t_render *render);
void	run_render(t_game *game, t_ray *ray, t_render *render, int x);
void	paint(t_game *game);
void	set_fnc(t_game *game);
void	raycasting(t_game *game);
int		exit_hook(t_game *game);
void	move_ver(int dir, t_game *game);
void	move_hor(int dir, t_game *game);
void	move_cam(int dir, t_game *game);
int		key_hook(int keycode, t_game *game);
void	init_game(t_game *game, char *file);
void	main_loop(t_game *game);
void	init_player(t_game *game);
void	set_text_num(t_ray *ray, t_render *render);

#endif
