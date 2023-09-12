/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:14:50 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/10 16:31:50 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

int	check_argv(char *argv)
{
	int	string;

	string = str_length(argv);
	if (string <= 4)
		return (0);
	if (argv[string - 1] == 'b' && argv[string - 2] == 'u'
		&& argv[string - 3] == 'c' && argv[string - 4] == '.')
		return (1);
	return (0);
}

void	init_game(t_game *game, char *file)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->height = 0;
	game->width = 0;
	game->player_count = 0;
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
	{
		perror("open Error");
		exit(1);
	}
	game->img = (t_img *)malloc(sizeof(t_img));
	if (!game->img)
		error("img error\n");
	game->img->img_no_name = NULL;
	game->img->img_so_name = NULL;
	game->img->img_we_name = NULL;
	game->img->img_ea_name = NULL;
	game->img->ceil_flag = 0;
	game->img->floor_flag = 0;
	game->mlx = mlx_init();
	if (!(game->mlx))
		error("mlx error\n");
}

void	check(void)
{
	system("leaks cub3d");
}

int	main(int argc, char **argv)
{
	t_game		game;

	atexit(check);
	if (argc != 2)
		error("Error\n");
	if (!(check_argv(argv[1])))
		error("Error\n");
	init_game(&game, argv[1]);
	read_map(&game);
	if (game.map == (void *)0)
		error("map error\n");
	check_map(&game);
	check_overlap(&game);
	exit(0);
}
