#include "cub3d.h"

int	exit_hook(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->east);
	mlx_destroy_image(game->mlx, game->img->west);
	mlx_destroy_image(game->mlx, game->img->south);
	mlx_destroy_image(game->mlx, game->img->north);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int move(int dir)
{
    if (dir == UP)
    {
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
    }
    else if (dir == DOWN)
    {
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
    }
    else if (dir == LEFT)
    {
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
    }
    else if (dir == RIGHT)
    {
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
    }
    return (0);
}

int	key_hook(int keycode, t_game *game)
{
	int	i;

	i = 0;
	if (keycode == KEY_ESC)
		exit_hook(game);
	if (keycode == KEY_UP)
		move(UP);
	else if (keycode == KEY_DOWN)
		move(DOWN);
	else if (keycode == KEY_LEFT)
		move(LEFT);
	else if (keycode == KEY_RIGHT)
		move(RIGHT);
    else if (keycode == KEY_CAM_RIGHT)
        move_cam();
    else if (keycode == KEY_CAM_LEFT)
        move_cam();
	else
		return (0);
    calc(game);
	draw(game);
	return (0);
}