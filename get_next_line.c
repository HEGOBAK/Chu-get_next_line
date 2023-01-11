#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 42

size_t ft_strlen(const char *str)
{
    size_t idx;

    idx = 0;
    while (str && str[idx])
        idx++;
    return (idx);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		count;
	int		idx;
	char	*newString;
	int		total_len;

	if (s1)
		total_len = ft_strlen(s1);
	if (s2)
		total_len = ft_strlen(s1) + ft_strlen(s2);
	newString = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!newString)
		return (NULL);
	idx = 0;
	count = 0;
	while (s1 && s1[idx])
		newString[count++] = s1[idx++];
	idx = 0;
	while (s2 && s2[idx])
		newString[count++] = s2[idx++];
	newString[count] = '\0';
	return (newString);
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
	char	*newString;

	idx = 0;
	while (str && str[idx] && str[idx] != '\n')
		idx++;
	newString = malloc(sizeof(char) * (idx + 1));
	if (!newString)
		return (NULL);
	if (ft_strchr(str, '\n') != 0)
		*ret = 1;
	idx = 0;
	while (str && str[idx] && str[idx] != '\n')
	{
		newString[idx] = str[idx];
		idx++;
	}
	newString[idx] = 0;
	return (newString);
}

char	*left_over(char *str)
{
	int		idx;
	int		count;
	char	*newString;

	idx = 0;
	while (str && str[idx] && str[idx] != '\n')
		idx++;
	newString = malloc(sizeof(char) * (ft_strlen(str) - idx + 1));
	if (!newString)
		return (NULL);
	count = 0;
	while (str && str[idx])
		newString[count++] = str[++idx];
	newString[count] = 0;
	return (newString);
}

int get_next_line(const int fd, char **line)
{
   static char	*str = NULL;
   char			buf[BUFFER_SIZE + 1];
   char			*temp;
   int			val;

	if (!line || BUFFER_SIZE <= 0 || fd < 0 || fd > 1023)
		return (-1);
	val = BUFFER_SIZE;
	while (val > 0)
	{
		val = read(fd, buf, BUFFER_SIZE);
		if (val == -1)
			return (-1);
		buf[val] = 0;
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

#include <fcntl.h>
int main()
{
   int fd = open("test", O_RDONLY);
   char *line = NULL;
   int ret = get_next_line(fd, &line);

   while (ret > 0)
   {
      printf ("%s\n", line);
      ret = get_next_line(fd, &line);
   }
   printf ("%s\n", line);
   free(line);
   return (0);
}