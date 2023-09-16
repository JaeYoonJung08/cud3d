/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:15:13 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 17:55:47 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void	put_mlx_img(t_game *game, char *path, t_img *img)
{
	int	wid;
	int	hei;

	img->img = NULL;
	img->img = mlx_xpm_file_to_image(game->mlx, path, &wid, &hei);
	if (!img->img)
		error("Error\nput_mlx_img\n");
	img->data = (int *)mlx_get_data_addr(img->img, &(img->bpp), \
		&(img->size_l), &(img->endian));
	if (!img->data)
		error("Error\nput_mlx_img\n");
}

static void	put_img(int *count, t_game *game, char *temp, int flag)
{
	char	*copy;

	copy = copy_string(temp);
	if (flag == NO)
	{
		put_mlx_img(game, temp, &(game->text[NO]));
		game->text[NO].path = copy;
	}
	else if (flag == SO)
	{
		put_mlx_img(game, temp, &(game->text[SO]));
		game->text[SO].path = copy;
	}
	else if (flag == EA)
	{
		put_mlx_img(game, temp, &(game->text[EA]));
		game->text[EA].path = copy;
	}
	else if (flag == WE)
	{
		put_mlx_img(game, temp, &(game->text[WE]));
		game->text[WE].path = copy;
	}
	(*count)++;
}

static void	check_extension(char *file)
{
	int	length;

	length = str_length(file);
	if (length <= 4)
		error("Error\nextension\n");
	if (!(file[length - 1] == 'm' && file[length - 2] == 'p' \
		&& file[length - 3] == 'x' && file[length - 4] == '.'))
		error("Error\nextension\n");
}

void	direction_chose(int	*count, t_game *game, char *new_line, char *temp)
{
	if (!(str_n_compare(temp, "NO", str_length(temp))) && \
		!(game->text[NO].path))
		put_img(count, game, new_line, NO);
	else if (!(str_n_compare(temp, "SO", str_length(temp))) \
		&& !(game->text[SO].path))
		put_img(count, game, new_line, SO);
	else if (!(str_n_compare(temp, "WE", str_length(temp))) \
		&& !(game->text[WE].path))
		put_img(count, game, new_line, WE);
	else if (!(str_n_compare(temp, "EA", str_length(temp))) \
		&& !(game->text[EA].path))
		put_img(count, game, new_line, EA);
	else
		error("Error\ndirection\n");
}

void	check_direction(char *line, t_game *game, int *count)
{
	char	**temp;
	int		temp_string;
	char	*new_line;

	new_line = NULL;
	temp = split_string(line, ' ');
	if (!temp)
		error("Error\ndirection\n");
	temp_string = 0;
	while (temp[temp_string])
		temp_string++;
	if (temp_string == 2)
	{
		new_line = no_new_line(temp[1]);
		check_extension(new_line);
	}
	if (temp_string == 2)
		direction_chose(count, game, new_line, temp[0]);
	else
		error("Error\ndirection\n");
	char_two_free(temp);
	free(new_line);
}
