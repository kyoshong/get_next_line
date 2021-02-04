/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:54:03 by hyospark          #+#    #+#             */
/*   Updated: 2021/02/05 01:24:21 by hyospark         ###   ########.fr       */
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
	while (cont[i] != '\n' && cont[i])
		i++;
	if (!cont[i])
		return (NULL);
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
	static char	*cont[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		check;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	check = 1;
	while (!line_check(cont[fd])&& check != 0)
	{
		if ((check = read(fd, buf, BUFFER_SIZE)) < 0)
			return (-1);
		buf[check] = '\0';
		temp = ft_strjoin(cont[fd], buf);
		if (cont[fd])
			free(cont[fd]);
		cont[fd] = temp;
	}
	*line = ft_strdup(cont[fd]);
	cont[fd] = re_backup(cont[fd]);
	if (check == 0)
	{
		free(cont[fd]);
		cont[fd] = NULL;
		return (0);
	}
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
		//printf("line : %s", line);
		printf("%d\n", ret);
	}
	printf("%d\n", ret);
		system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
}