/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:16:23 by hyospark          #+#    #+#             */
/*   Updated: 2021/02/04 02:52:08 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*n_str;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	if (!(n_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		n_str[i++] = *s1++;
	while (*s2)
		n_str[i++] = *s2++;
	n_str[i] = '\0';
	return (n_str);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char	*ft_strdup(char *s)
{
	char	*tem;
	int		i;
	int		len;

	if (!s)
		return ("");
	if ((len = line_check(s)) == 0)
		return (s);
	if (!(tem = malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i <= len)
	{
		tem[i] = s[i];
		i++;
	}
	tem[i] = '\0';
	return (tem);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
