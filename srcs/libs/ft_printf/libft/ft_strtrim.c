/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:50:38 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 03:10:44 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

static size_t	observe_set(char const s, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	size;
	size_t	start;
	size_t	end;
	char	*s_dst;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && observe_set(s1[start], set))
		start++;
	if (!s1[start])
		return (ft_calloc(1, 1));
	while (s1[end] && observe_set(s1[end], set))
		end--;
	size = (end - start) + 1;
	s_dst = (char *)malloc((size + 1) * sizeof(char));
	if (s_dst == NULL)
		return (NULL);
	i = 0;
	while (i < size && start <= end && s1 != (void *)0)
		s_dst[i++] = s1[start++];
	s_dst[size] = '\0';
	return (s_dst);
}

// int main()
// {
// 	char	*val;
// 	val = ft_strtrim("aaaaaaaaa", "a");
// 	printf("'%s'\n", val);
// }
