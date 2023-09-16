/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naki <naki@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:14:50 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 15:31:56 by naki             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static int	check_argv(char *argv)
{
	int	string;

	string = str_length(argv);
	if (string <= 4)
		return (1);
	if (!(argv[string - 1] == 'b' && argv[string - 2] == 'u' \
			&& argv[string - 3] == 'c' && argv[string - 4] == '.'))
		return (1);
	return (0);
}

static void	init_buf(t_game *game)
{
	int	i;
	int	j;

	game->buf = (int **)malloc(sizeof(int *) * WIN_HEIGHT);
	i = 0;
	while (i < WIN_HEIGHT)
	{
		game->buf[i] = (int *)malloc(sizeof(int) * WIN_WIDTH);
		i++;
	}
	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			game->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

// void	check(void)
// {
// 	system("leaks cub3d");
// }

int	main(int argc, char **argv)
{
	t_game		game;

	//atexit(check);
	if (argc != 2 || check_argv(argv[1]))
		error("Error\ninvalid arg\n");
	init_game(&game, argv[1]);
	read_map(&game);
	if (game.map == (void *)0)
		error("Error\nmap\n");
	check_map(&game);
	check_overlap(&game);
	init_player(&game);
	init_rgb(&game);
	init_buf(&game);
	game.mlx = mlx_init();
	if (game.mlx == (void *)0)
		error("Error\nmlx\n");
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	game.img->img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	game.img->data = (int *)mlx_get_data_addr(game.img->img, \
	&(game.img->bpp), &(game.img->size_l), &(game.img->endian));
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_hook, &game);
	mlx_hook(game.win, X_BUTTON, 0, &exit_hook, &game);
	main_loop(&game);
	mlx_loop(game.mlx);
}
