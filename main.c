#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen (const char *str);
char	*get_next_line (int fd);

#include <time.h>
int main(void)
{
	char	*s;
	int		fd;
	fd = open("test.txt", O_RDONLY);
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		/*sleep(1);*/
		free(s);
	}
	close(fd);
	system("leaks a.out");
}
