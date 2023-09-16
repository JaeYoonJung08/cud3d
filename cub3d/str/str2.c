/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:08:53 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/16 17:06:44 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

char	*copy_string(const char *string)
{
	char	*temp;
	int		i;
	int		count;

	i = 0;
	count = str_length(string);
	temp = (char *)malloc(count * sizeof(char) + 1);
	if (!temp)
		return (0);
	while (string[i])
	{
		temp[i] = string[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*no_new_line(char *line)
{
	int		i;
	char	*no_newline;

	if (!line)
		return (NULL);
	no_newline = (char *)malloc(sizeof(char) * (str_length(line) + 1));
	i = 0;
	while (line[i])
	{
		no_newline[i] = line[i];
		if (line[i] == '\n')
			break ;
		i++;
	}
	no_newline[i] = '\0';
	return (no_newline);
}
