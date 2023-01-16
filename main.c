#include <fcntl.h>
#include "get_next_line.h"
//#include "get_next_line_bonus.h"

int main()
{
	int i = 100;
    int fd = open("test", O_RDONLY);
    char *line;

	while (i)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("\nNULL returned\n");
			break ;
		}
		printf("line : %s", line);
		free(line);
		i--;
	}
    close(fd);
    return (0);
}