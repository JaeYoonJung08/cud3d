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
	//.cub 길이를 셈 -> 4보다 작으면 에러
	if (string <= 4)
		return (0);
	//.cub가 맞는지 확인
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
	// game->img->img_no = NULL;
	// game->img->img_so = NULL;
	// game->img->img_we = NULL;
	// game->img->img_ea = NULL;
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
	//1. argc 2가 아닐 때 에라
	if (argc != 2)
		error("Error\n");
	//2. .cub 체크
	if (!(check_argv(argv[1])))
		error("Error\n");
	//3. game 구조체 초기화
	init_game(&game, argv[1]);
	//4. gnl
	read_map(&game);
	//빈 파일 검사
	if (game.map == (void *)0)
		error("map error\n");
	//5.맵 유효성 검사
	check_map(&game);
	printf("dEBN\n");
	//6.rgb, direction 중복 검검사사
	check_overlap(&game);

	//해야될 일 
	//1. 빈 파일, 빈 map 일 때 세그 고치기                   (o) cub3d.c, cub3d_check_map.c if문 추가 	if (map_copy == (void *)0)
	//2. 캐릭터 없을 때 -- ?								(o) cub3d_check_map -> if문에 추가 if (player_count == 0)
	//3. 캐릭터 주위 검사 추가하기							(o) cub3d_check_zero -> if문 추가 
	//4. 캐릭터가 두 개 이상 들어올 때						(o)
	//5. cun에서 똑같은 거 2개 들어오면 터짐				()

	// printf("player : %d\n",game.player_count);
	// for (int i = 0; i < 3; i++)
	// 	printf("ceil : %d\n" ,game.img->ceil[i]);
	// for (int i = 0; i < 3; i++)
	// 	printf("floor : %d\n" ,game.img->floor[i]);
	// int j = 0;
	// while (game.map_copy[j])
	// {
	// 	printf("%s\n", game.map_copy[j]);
	// 	j++;
	// }
	//릭은 일단 나중에
	//char_two_free(game.map_copy);
	// free(game.img->img_ea);
	// free(game.img->img_no);
	// free(game.img->img_so);
	// free(game.img->img_we);
	// free(game.img);
	// free(game.mlx);
	exit(0);
}
