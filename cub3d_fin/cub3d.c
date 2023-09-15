/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:14:50 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/15 18:41:47 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void	check_argv(char *argv)
{
	int	string;

	string = str_length(argv);
	if (string <= 4)
		error("Error\ninvalid argv\n");
	if (!(argv[string - 1] == 'b' && argv[string - 2] == 'u' \
		&& argv[string - 3] == 'c' && argv[string - 4] == '.'))
		error("Error\ninvalid argv\n");
}

// void	check(void)
// {
// 	system("leaks cub3d");
// }

int	main(int argc, char **argv)
{
	t_game		game;

    //atexit(check);
	if (argc != 2)
		error("Error\ninvalid argc\n");
	check_argv(argv[1]);
	init_game(&game, argv[1]);
	read_map(&game);
	if (game.map == (void *)0)
		error("Error\nmap\n");
	check_map(&game);
	check_overlap(&game);
	init_player(&game);
	init_rgb(&game);
	init_texture(&game);
	load_texture(&game);
	game.win = mlx_new_window(game.mlx, WIN_WIDTH, \
	WIN_HEIGHT, "cub3d");
	game.img_info->img = mlx_new_image(game.mlx, WIN_WIDTH, WIN_HEIGHT);
	game.img_info->data = (int *)mlx_get_data_addr(game.img_info->img, \
	&game.img_info->bpp, &game.img_info->size_l, &game.img_info->endian);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, X_BUTTON, 0, &exit_hook, &game);
	main_loop(&game);
	mlx_loop(game.mlx);
}
