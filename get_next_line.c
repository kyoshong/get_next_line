/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:54:03 by hyospark          #+#    #+#             */
/*   Updated: 2021/02/04 02:37:56 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*re_backup(char *cont)
{
	int len_c;
	int i;
	int j;
	char *temp;

	if (!cont)
		return (NULL);
	i = 0;
	while (cont[i] != '\n')
	{
		i++;
		if (!cont[i])
			return (0);
	}
	len_c = ft_strlen(cont);
	if (!(temp = malloc(sizeof(char) * (len_c - i) + 1)))
		return (NULL);
	i++;
	j = 0;
	while (cont[i])
		temp[j++] = cont[i++];
	temp[j] = '\0';
	return (temp);
}

int		line_check(char *cont)
{
	int i;

	if (!cont)
		return (0);
	i = 0;
	while (cont[i])
	{
		if (cont[i++] == '\n')
			return (i);
	}
	return (0);
}

int get_next_line(int fd, char **line)
{
	static char	*cont[FOPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		check;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	check = 1;
	while (line_check(cont[fd]) == 0 && check > 0)
	{
		printf("fucking cont : %s\n", cont[fd]);
		printf("fucking cont : %s\n", cont[fd]);
		if ((check = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		printf("before cont : %s\n", cont[fd]);
		printf("check : %zd\n", check);
		buf[check] = '\0';
		printf("buf : %s\n", buf);
		printf("before cont : %s\n", cont[fd]);
		cont[fd] = ft_strjoin(cont[fd], buf);
		printf("after cont : %s\n", cont[fd]);
	}
	*line = ft_strdup(cont[fd]);
	printf("line : %s\n", *line);
	cont[fd] = re_backup(cont[fd]);
	if (check == 0)
		return (0);
	return (1);
}
int	main()
{
	int		ret;
	int		fd;
	char	*line;

//*line이 선언된 상태로 get_next_line 함수로 넘어감

	fd = open("text.txt", O_RDONLY);

	while ((ret = (get_next_line(fd, &line)) > 0))
	{
		printf("-------ww---------");
		printf("%s", line);
	}
	printf("%s", line);
}