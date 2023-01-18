/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:25:08 by jchu              #+#    #+#             */
/*   Updated: 2023/01/18 16:25:41 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2, int val)
{
	int		i;
	int		idx;
	char	*newstring;

	i = 0;
	idx = 0;
	newstring = malloc(sizeof(*s1) * (ft_strlen(s1) + val + 1));
	if (!newstring)
		return (NULL);
	if (s1)
	{
		while (s1[idx])
		{
			newstring[idx] = s1[idx];
			idx++;
		}
		free(s1);
	}
	while (val > 0)
	{
		newstring[idx++] = s2[i++];
		val--;
	}
	newstring[idx] = '\0';
	return (newstring);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (!str && !c)
		return ((char *)str);
	return (NULL);
}

int	count_idx(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		i++;
		if (str[i - 1] == '\n')
			break ;
	}
	return (i);
}

char	*pickup(char *str)
{
	char	*line;
	int		idx;

	idx = 0;
	if (!str || !str[idx])
		return (NULL);
	idx = count_idx(str);
	line = malloc(sizeof(char) * (idx + 1));
	if (!line)
		return (NULL);
	idx = 0;
	while (str && str[idx])
	{
		line[idx] = str[idx];
		idx++;
		if (str[idx - 1] == '\n')
			break ;
	}
	line[idx] = 0;
	return (line);
}

char	*left_over(char *str)
{
	int		i;
	int		idx;
	int		count;
	char	*newstring;

	count = 0;
	if (!str || !str[count])
		return (NULL);
	idx = ft_strlen(str) - count_idx(str);
	if (!idx)
	{
		free(str);
		return (NULL);
	}
	newstring = malloc(sizeof(char) * (idx + 1));
	if (!newstring)
		return (NULL);
	i = count_idx(str);
	while (count < idx)
		newstring[count++] = str[i++];
	newstring[count] = '\0';
	free(str);
	return (newstring);
}
