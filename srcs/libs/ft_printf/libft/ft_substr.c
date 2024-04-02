/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:31:35 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/10 15:12:26 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	count;

// 	count = 0;
// 	while (str[count] != '\0')
// 		count++;
// 	return (count);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*mem_sec;

	if (!s)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s))
	{
		mem_sec = ft_strdup("");
		return (mem_sec);
	}
	i = ft_strlen(s);
	if (i < len)
		len = i;
	mem_sec = (char *)malloc((len + 1) * sizeof(char));
	if (mem_sec == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0' && i < len)
	{
		mem_sec[i] = s[start + i];
		i++;
	}
	mem_sec[i] = '\0';
	return (mem_sec);
}

// int	main(int ac, char **av)
// {
// 	char				*check_substr;
// 	unsigned int		s;
// 	size_t				len;

// 	if (ac == 4)
// 	{
// 		s = atoi(av[2]);
// 		len = atoi(av[3]);
// 		check_substr = ft_substr(av[1], s, len);
// 		printf("\nInput string is:'%s'\n", av[1]);
// 		printf("Return value is:'%s'\n\n", check_substr);
// 	}
// 	else
// 		printf("pls enter 3 arg\n");
// }
