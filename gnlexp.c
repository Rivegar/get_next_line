#include "get_next_line.h" // Incluye la cabecera get_next_line.h que contiene las declaraciones de las funciones utilizadas.

static char *next_line(char **temp)
{
	char *line;
	char *ptr;

	ptr = *temp; // Asigna a 'ptr' el valor de la dirección de memoria apuntada por 'temp'
	while (*ptr && *ptr != '\n') // Mientras 'ptr' no apunte a un '\n' ni al final de la cadena...
		++ptr; // ... incrementa el valor de 'ptr'
	ptr += (*ptr == '\n'); // Si 'ptr' apunta a un '\n', incrementa su valor de nuevo
	line = ft_substr (*temp, 0, (size_t)(ptr - *temp)); // Extrae la cadena de caracteres que va desde el inicio de '*temp' hasta 'ptr', y la almacena en 'line'
	if (!line) // Si 'line' es NULL (es decir, si la extracción no se pudo realizar)...
	{
		free (*temp); // ... libera la memoria apuntada por '*temp'...
		return (NULL); // ... y devuelve NULL
	}
	ptr = ft_substr (ptr, 0, ft_strlen (ptr)); // Extrae la cadena de caracteres que va desde 'ptr' hasta el final de la cadena, y la almacena en 'ptr'
	free (*temp); // Libera la memoria apuntada por '*temp'
	*temp = ptr; // Asigna a '*temp' el valor de 'ptr'
	return (line); // Devuelve la línea extraída
}

static char *read_line(char *temp, int fd, char *buf)
{
	ssize_t r;

	r = 1; // Inicializa 'r' con un valor distinto de cero
	while (r && !ft_strchr(temp, '\n')) // Mientras no se haya encontrado un '\n' en 'temp' y se siga leyendo correctamente del archivo...
	{
		r = read (fd, buf, BUFFER_SIZE); // ... lee del archivo 'fd' en bloques de tamaño 'BUFFER_SIZE'...
		if (r == -1) // ... y si se produce un error al leer...
		{
			free (buf); // ... libera la memoria apuntada por 'buf'...
			free (temp); // ... libera la memoria apuntada por 'temp'...
			return (NULL); // ... y devuelve NULL
		}
		buf[r] = 0; // Agrega el caracter nulo al final de 'buf'
		temp = ft_strjoin_free(temp, buf); // Concatena 'buf' a 'temp' y libera la memoria apuntada por 'temp' al mismo tiempo
	}
	free (buf); // Libera la memoria apuntada por 'buf'
	return (temp); // Devuelve la cadena de caracteres 'temp'
}

char *get_next_line(int fd)
{
	static char *temp[4096]; // Variable estática que almacena el contenido de los archivos abiertos
	char *buf; // Puntero a una zona de memoria reservada para lectura

	if (fd == -1 || BUFFER_SIZE < 1) // Si el descriptor de archivo es inválido o el tamaño del búfer es menor que 1...
		return (NULL); // ... devuelve NULL
	if (!temp[fd]) // Si 'temp[fd]' no contiene nada (es decir, si es la primera vez que se lee el archivo 'fd')...
temp[fd] = ft_strdup(""); // ... inicializa 'temp[fd]' con una cadena vacía
buf = (char*)malloc(BUFFER_SIZE + 1); // Reserva memoria para 'buf'
if (!buf) // Si la reserva de memoria falla...
return (NULL); // ... devuelve NULL
temp[fd] = read_line(temp[fd], fd, buf); // Lee una línea de 'fd' y la almacena en 'temp[fd]'
if (!temp[fd]) // Si no se pudo leer del archivo...
return (NULL); // ... devuelve NULL
return (next_line(&temp[fd])); // Devuelve la siguiente línea del archivo
}
