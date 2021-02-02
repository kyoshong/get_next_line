/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyospark <hyospark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:16:23 by hyospark          #+#    #+#             */
/*   Updated: 2021/02/03 03:06:19 by hyospark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n_str;
	int		i;
	char	*str1;
	char	*str2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!(n_str = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1)))
		return (NULL);
	i = 0;
	while (*str1 != '\0')
		n_str[i++] = *str1++;
	while (*str2 != '\0')
		n_str[i++] = *str2++;
	n_str[i] = '\0';
	return (n_str);
}

char	*ft_strdup(char *s)
{
	char	*tem;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(tem = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		tem[i] = s[i];
		i++;
	}
	tem[i] = '\0';
	return (tem);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
