/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:28:39 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/27 17:41:58 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len ++;
	return (len);
}

char	*ft_strchr_gnl(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen_gnl(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

// Trust s1 to be malloced. If NULL, frees the caller's buffer
char	*ft_strjoin_gnl(char *s1, char *s2)
{
	ssize_t	i;
	size_t	count;
	size_t	size;
	char	*tmp;

	if (!s2)
		return (free(s1), NULL);
	size = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	tmp = (char *)malloc((size + 1) * sizeof(char));
	if (!tmp)
		return (free(s1), free(tmp), NULL);
	i = -1;
	count = 0;
	if (s1)
		while (s1[++i] != '\0')
			tmp[i] = s1[i];
	while (s2[count] != '\0')
		tmp[i++] = s2[count++];
	tmp[size] = '\0';
	free(s1);
	return (tmp);
}
