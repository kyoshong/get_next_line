/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:16:37 by hyospark          #+#    #+#             */
/*   Updated: 2021/02/03 03:25:10 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **line);
char	*re_backup(char *cont);
int		line_check(char *cont);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s);
size_t	ft_strlen(char const *str);

# endif