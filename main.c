#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main() {
	int fd = open("get_next_line.h", O_RDONLY);
	int i = 0;
	char *str;

	while (i < 20)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		i++;
	}
}