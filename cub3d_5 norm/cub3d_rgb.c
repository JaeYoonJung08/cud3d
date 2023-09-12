/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:57:50 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/10 16:46:38 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "header/cub3d.h"

// ','과 숫자들이 잘 들어왔는지 검사
void	check_rgb_invalid(char *temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		if (!(temp[i] == ',' || (temp[i] >= '0' && temp[i] <= '9') || \
			temp[i] == '\n'))
			error("rgb_invalid_Erro1r\n");
		i++;
	}
}

//들어온 rgb가 잘 맞게 들어왔는지 검사하고 atoi
void	check_color(char **temp_split, int *array)
{
	int	temp_string;

	temp_string = 0;
	while (temp_split[temp_string])
		temp_string++;
	if (temp_string != 3)
		error("rgb_color_Error\n");
	temp_string = 0;
	while (temp_split[temp_string])
	{
		array[temp_string] = int_atoi(temp_split[temp_string]);
		temp_string++;
	}
}

//rgb ,와 숫자인지 검사 한 후 rgb 값 넣어주기
void	input_rgb(char *temp, int *count, int *array, int *check)
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
		error("comma error\n");
	check_rgb_invalid(temp);
	comma_split = split_string(temp, ',');
	if (!comma_split)
		error("rgb_input_Error\n");
	check_color(comma_split, array);
	(*count)++;
	char_two_free(comma_split);
	*check = 1;
}

//rgb F와 C 체크
void	check_rgb(char *line, t_game *game, int *count)
{
	char	**temp;
	int		temp_string;
	char	*new_line;

	new_line = NULL;
	temp = split_string(line, ' ');
	if (!temp)
		error("rgb_Error\n");
	temp_string = 0;
	while (temp[temp_string])
		temp_string++;
	if (temp_string == 2)
		new_line = no_new_line(temp[1]);
	if (!(str_n_compare(temp[0], "F", str_length(temp[0]))) \
		&& temp_string == 2 && game->img->floor_flag == 0)
		input_rgb(new_line, count, game->img->floor, &(game->img->floor_flag));
	else if (!(str_n_compare(temp[0], "C", str_length(temp[0]))) \
		&& temp_string == 2 && game->img->ceil_flag == 0)
		input_rgb(new_line, count, game->img->ceil, &(game->img->ceil_flag));
	else
		error("rgb_Error\n");
	char_two_free(temp);
	free(new_line);
}
