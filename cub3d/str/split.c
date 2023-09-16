/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaeyojun <jaeyojun@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 22:47:28 by jaeyojun          #+#    #+#             */
/*   Updated: 2023/09/06 18:04:27 by jaeyojun         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static int	string_check(char s, char c)
{
	if (s == c)
		return (1);
	return (0);
}

static int	malloc_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (string_check(s[i], c) == 1))
			i++;
		if (s[i])
		{
			count++;
			i++;
		}
		while (s[i] && (string_check(s[i], c) == 0))
			i++;
	}
	return (count);
}

static char	*word_input(char const *s, char c)
{
	int		i;
	char	*temp;
	int		count;
	int		j;

	j = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0' && string_check(s[i], c) == 0)
	{
		i++;
		count++;
	}
	temp = (char *)malloc(sizeof(char) * count + 1);
	if (!temp)
		return (0);
	while (s[j] != '\0' && string_check(s[j], c) == 0)
	{
		temp[j] = s[j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	**split_string(char const *s, char c)
{
	char	**temp;
	int		count;
	int		size;

	count = 0;
	size = malloc_count(s, c);
	temp = (char **)malloc(sizeof(char *) * (size + 1));
	if (!temp)
		return (0);
	while (*s)
	{
		while (*s && string_check(*s, c) == 1)
			s++;
		if (*s)
		{
			temp[count++] = word_input(s, c);
			if (temp[count - 1] == 0)
				return (char_two_free(temp));
			s++;
		}
		while (*s && (string_check(*s, c) == 0))
			s++;
	}
	temp[count] = 0;
	return (temp);
}
