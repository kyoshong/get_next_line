/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:54:03 by hyospark          #+#    #+#             */
/*   Updated: 2021/02/03 03:25:06 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*re_backup(char *cont)
{
	int len;
	int len_c;
	int i;
	char *temp;

	if (!cont)
		return (NULL);
	while (cont[i] && cont[i] != '\n')
		i++;
	if (!cont[i])
	{
		free(cont);
		return (0);
	}
	len_c = ft_strlen(cont);
	if (!(temp = malloc(sizeof(char) * (len_c - i) + 1)))
		return (NULL);
	i++;
	while (cont[i])
		temp[len++] = cont[i++];
	temp[len] = '\0';
	free(cont);
	return (temp);
}

int		line_check(char *cont)
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
	ssize_t		check;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	check = 1;
	while (!line_check(cont[fd]) && check != 0)
	{
		if ((check = read(fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		cont[fd] =  ft_strjoin(cont[fd], buf);
	}
	*line = ft_strdup(cont[fd]);
	cont[fd] = re_backup(cont[fd]);
	if (check == 0)
		return (0);
	return (1);
}
