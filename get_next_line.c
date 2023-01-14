/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchu <jchu@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:36:33 by jchu              #+#    #+#             */
/*   Updated: 2023/01/14 19:29:33 by jchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	norm(const int fd, char *buf, int *val)
{
	*val = read(fd, buf, BUFFER_SIZE);
	if (*val == -1)
		return ;
	buf[*val] = 0;
}

int	get_next_line(const int fd, char **line)
{
	static char		*str = NULL;
	char			buf[BUFFER_SIZE + 1];
	char			*temp;
	int				val;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (-1);
	val = BUFFER_SIZE;
	while (val > 0)
	{
		norm(fd, buf, &val);
		temp = str;
		str = ft_strjoin(temp, buf);
		free(temp);
		if (ft_strchr(str, '\n'))
			break ;
	}
	*line = pickup(str, &val);
	temp = str;
	str = left_over(temp);
	free(temp);
	return (val);
}

/*
#include <fcntl.h>
int main()
{
   int fd = open("test", O_RDONLY);
   char *line = NULL;
   int ret = get_next_line(fd, &line);

   while (ret > 0)
   {
      printf ("%s", line);
      ret = get_next_line(fd, &line);
   }
   printf ("%s", line);
   free(line);
   return (0);
}*/