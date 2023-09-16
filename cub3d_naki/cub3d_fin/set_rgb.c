/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:57:50 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 16:24:07 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

static void	check_rgb_invalid(char *temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		if (!(temp[i] == ',' || (temp[i] >= '0' && temp[i] <= '9') || \
			temp[i] == '\n'))
			error("Error\nrgb_invalid\n");
		i++;
	}
}

static void	check_color(char **temp_split, int *array)
{
	int	temp_string;

	temp_string = 0;
	while (temp_split[temp_string])
		temp_string++;
	if (temp_string != 3)
		error("Error\nrgb_color\n");
	temp_string = 0;
	while (temp_split[temp_string])
	{
		array[temp_string] = int_atoi(temp_split[temp_string]);
		temp_string++;
	}
}

static void	input_rgb(char *temp, int *count, int *array, int *check)
{
	char	**comma_split;
	int		comma;
	int		i;

	i = 0;
	comma = 0;
	while (temp[i])
	{
		if (temp[i] == ',')
			comma++;
		i++;
	}
	if (comma >= 3)
		error("Error\ncomma\n");
	check_rgb_invalid(temp);
	comma_split = split_string(temp, ',');
	if (!comma_split)
		error("Error\nrgb_split\n");
	check_color(comma_split, array);
	(*count)++;
	char_two_free(comma_split);
	*check = 1;
}

void	init_rgb(t_game *game)
{
	game->color->c_color = (game->color->ceil[0] << 16) | \
		(game->color->ceil[1] << 8) | game->color->ceil[2];
	game->color->f_color = (game->color->floor[0] << 16) | \
		(game->color->floor[1] << 8) | game->color->floor[2];
}

void	check_rgb(char *line, t_game *game, int *count)
{
	char	**temp;
	int		temp_string;
	char	*new_line;

	new_line = NULL;
	temp = split_string(line, ' ');
	if (!temp)
		error("Error\nrgb_split\n");
	temp_string = 0;
	while (temp[temp_string])
		temp_string++;
	if (temp_string == 2)
		new_line = no_new_line(temp[1]);
	if (!(str_n_compare(temp[0], "F", str_length(temp[0]))) \
		&& temp_string == 2 && game->color->floor_flag == 0)
		input_rgb(new_line, count, game->color->floor, \
		&(game->color->floor_flag));
	else if (!(str_n_compare(temp[0], "C", str_length(temp[0]))) \
		&& temp_string == 2 && game->color->ceil_flag == 0)
		input_rgb(new_line, count, game->color->ceil, \
		&(game->color->ceil_flag));
	else
		error("Error\nrgb_invalid\n");
	char_two_free(temp);
	free(new_line);
}
