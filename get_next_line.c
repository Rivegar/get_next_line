/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arivero- <arivero-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:12:10 by arivero-          #+#    #+#             */
/*   Updated: 2023/04/12 15:59:37 by arivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
	char		*str;
	static char	buffer[BUFFER_SIZE];
	size_t		i;
	int			read_bytes;

	i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(!str)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	while(read_bytes > 0)
	{

	}
	return (str);
}
