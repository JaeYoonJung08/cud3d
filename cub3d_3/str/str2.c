/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 19:08:53 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/06 20:26:23 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

char	*ft_strdup(const char *string)
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
