#include "cub3d.h"

void    set_image(t_game *game)
{
	int	hei;
	int	wid;

	game->img->east = mlx_xpm_file_to_image(game->mlx, \
	game->img->path_e, &wid, &hei);
	game->img->west = mlx_xpm_file_to_image(game->mlx, \
	game->img->path_w, &wid, &hei);
	game->img->south = mlx_xpm_file_to_image(game->mlx, \
	game->img->path_s, &wid, &hei);
	game->img->north = mlx_xpm_file_to_image(game->mlx, \
	game->img->path_n, &wid, &hei);
}

int main(int argc, char **argv)
{
    t_game  *game;

    game = ft_calloc(1, sizeof(t_game));
    if (argc == 2)
    {
        game->map = parse(argv);
        game->mlx = mlx_init();
        set_image(game);
        game->win = mlx_new_windeow(game->mlx, game->width * 64, \
        game->height * 64, "cub3d");
        ray_casting(game);
        mlx_key_hook(game->win, key_hook, game);
        mlx_hook(game->win, X_BUTTON, 0, &exit_hook, game);
        mlx_loop(game->mlx);
    }
    return (0);
}