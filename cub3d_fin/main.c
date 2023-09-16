/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:14:50 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 17:54:53 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static int	check_argv(char *argv)
{
	int		string;
	int		temp_count;
	char	**temp;

	temp = split_string(argv, '/');
	if (!temp)
		error("Error\nsplit_argv\n");
	temp_count = 0;
	while (temp[temp_count])
		temp_count++;
	temp_count--;
	string = str_length(temp[temp_count]);
	if (string <= 4)
		return (char_two_free(temp), 1);
	if (!(temp[temp_count][string - 1] == 'b' && \
		temp[temp_count][string - 2] == 'u' \
		&& temp[temp_count][string - 3] == 'c' \
		&& temp[temp_count][string - 4] == '.'))
		return (char_two_free(temp), 1);
	return (char_two_free(temp), 0);
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

int	main(int argc, char **argv)
{
	t_game		game;

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
