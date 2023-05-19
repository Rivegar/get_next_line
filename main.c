#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen (const char *str);
char	*get_next_line (int fd);

#include <time.h>
int main(void)
{
	char	*s;
	int		fd;
	//fd = open("test.txt", O_RDONLY);

	int		consola;
	size_t len = 0;
	char *line = NULL;
	consola = getline(&line, &len, stdin);

	//Lectura de STDIN
	/*while ((s = get_next_line(consola)))
	{
		printf("La línea es: %s", s);
		//sleep(1);
		free(s);
	}*/
	//LECTURA ARCHIVO FD
	while ((s = get_next_line(fd)))
	{
		printf("La línea es: %s", s);
		//sleep(1);
		free(s);
	}
	close(fd);
	//system("leaks a.out");
	return (0);
}
