/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:24:57 by jchu              #+#    #+#             */
/*   Updated: 2023/01/18 16:30:58 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	idx = 0;
	while (str && str[idx])
		idx++;
	return (idx);
}

char	*ft_get_line(int fd, char *str)
{
	char	*buf;
	int		val;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	val = read(fd, buf, BUFFER_SIZE);
	while (val > 0)
	{
		str = ft_strjoin(str, buf, val);
		if (ft_strchr(str, '\n'))
			break ;
		val = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	if (val == -1)
	{
		if (str)
			free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char		*str[1024];
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	str[fd] = ft_get_line(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = pickup(str[fd]);
	str[fd] = left_over(str[fd]);
	return (line);
}
