/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:36:33 by jchu              #+#    #+#             */
/*   Updated: 2023/01/16 18:29:00 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*str;
	char			*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (NULL);
	str = ft_get_line(fd, str);
	if (!str)
		return (NULL);
	line = pickup(str);
	str = left_over(str);
	return (line);
}
