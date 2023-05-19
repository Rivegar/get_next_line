/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivero- <arivero-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 16:44:42 by rcuesta-          #+#    #+#             */
/*   Updated: 2023/05/19 11:51:02 by arivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*get_next_line(int fd);

 /*int main()
 {
 	//int fd = open("hhgttg.txt", O_RDONLY);
 	char *ptr;
 	ptr = get_next_line(42);
 	printf("Line: %s", ptr);
 	//system("leaks a.out\n");
 	return (0);
 }*/

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		n;

	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("Error al abrir el archivo");
	else
	{
		n = 1;
		line = get_next_line(fd);
		while (line)
		{
			printf("%i- %s", n, line);
			free (line);
			line = get_next_line(fd);
			n++;
		}
		printf("%i- %s", n, line );
	}
	// system("leaks a.out\n");
	close(fd);
	return (0);
}
