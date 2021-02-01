/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:54:03 by hyospark          #+#    #+#             */
/*   Updated: 2021/02/01 22:29:00 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*return_line(char *line, char *cont)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (cont[j] != '\n' && cont[j])
		line[i++] = cont[j++];
	line[j] = '\0';
	return (line);
}

int		count_newline(char *cont)
{
	int i;

	i = 0;
	while (cont[i])
	{
		if (cont[i++] == '\n')
			return (1);
	}
	return (0);
}
int get_next_line(int fd, char **line)
{
	static char	*cont[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			check;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if ((check = read(fd, buf, BUFFER_SIZE)) == -1)
		return (-1);
	while (count_newline(buf))
	{
		
	}
	
}
