/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:41:56 by jchu              #+#    #+#             */
/*   Updated: 2023/01/14 19:25:55 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str && str[idx])
		idx++;
	return (idx);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		count;
	int		idx;
	char	*newstring;
	int		total_len;

	if (s1)
		total_len = ft_strlen(s1);
	if (s2)
		total_len = ft_strlen(s1) + ft_strlen(s2);
	newstring = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!newstring)
		return (NULL);
	idx = 0;
	count = 0;
	while (s1 && s1[idx])
		newstring[count++] = s1[idx++];
	idx = 0;
	while (s2 && s2[idx])
		newstring[count++] = s2[idx++];
	newstring[count] = '\0';
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

char	*pickup(char *str, int *ret)
{
	int		idx;
	char	*newstring;

	idx = 0;
	while (str && str[idx] && str[idx] != '\n')
		idx++;
	newstring = malloc(sizeof(char) * (idx + 2));
	if (!newstring)
		return (NULL);
	if (ft_strchr(str, '\n') != 0)
		*ret = 1;
	idx = 0;
	while (str && str[idx] && str[idx] != '\n')
	{
		newstring[idx] = str[idx];
		idx++;
	}
	newstring[idx] = '\n';
	newstring[idx + 1] = 0;
	return (newstring);
}

char	*left_over(char *str)
{
	int		idx;
	int		count;
	char	*newstring;

	idx = 0;
	while (str && str[idx] && str[idx] != '\n')
		idx++;
	newstring = malloc(sizeof(char) * (ft_strlen(str) - idx + 1));
	if (!newstring)
		return (NULL);
	count = 0;
	while (str && str[idx])
		newstring[count++] = str[++idx];
	newstring[count] = 0;
	return (newstring);
}
