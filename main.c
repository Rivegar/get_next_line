#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen (const char *str);
char	*get_next_line (int fd);

int 	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		write (1, line, ft_strlen (line));
		free (line);
	}
	return (0);
}
