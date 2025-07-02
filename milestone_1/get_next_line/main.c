#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd = open("text.txt", O_RDONLY);
	int i = 0;
	char *line;
	while (i < 8)
	{
		line = get_next_line(fd);
		i++;
		printf("%s", line);
		free(line);
	}
	close(fd);
}