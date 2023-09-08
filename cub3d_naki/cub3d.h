#ifndef CUB3D_H
#define CUB3D_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "./mlx/mlx.h"

# define X_BUTTON       	17
# define KEY_ESC			53
# define KEY_UP				13
# define KEY_DOWN			1
# define KEY_RIGHT			2
# define KEY_LEFT			0
# define KEY_CAM_RIGHT      124
# define KEY_CAM_LEFT       123

typedef enum    e_arrow
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}

typedef struct s_game
{
    t_img   *img;
	void	*mlx;
	void	*win;
	char	**map;
    char    **buf;
	int		width;
	int		height;
}	t_game;

typedef struct  s_img
{
	void	*east;
	void	*west;
	void	*south;
	void	*north;
    char    *path_e;
    char    *path_w;
    char    *path_s;
    char    *path_n;
}   t_img;

#endif