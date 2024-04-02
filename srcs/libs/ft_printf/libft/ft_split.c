/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:46:35 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/12 17:54:33 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_split_result(char **split_result)
{
	char	**ptr;

	ptr = split_result;
	while (*ptr)
	{
		free(*ptr);
		ptr++;
	}
	free(split_result);
	return (NULL);
}

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;
	int		is_word;

	count = 0;
	i = 0;
	is_word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (is_word == 0)
			{
				is_word = 1;
				count++;
			}
		}
		else
			is_word = 0;
		i++;
	}
	return (count);
}

static char	*ft_strndup(const char *src, size_t n)
{
	char	*dup_str;

	dup_str = (char *)malloc((n + 1) * sizeof(char));
	if (dup_str == NULL)
		return (NULL);
	ft_memcpy(dup_str, src, n);
	dup_str[n] = '\0';
	return (dup_str);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	char		*temp;

	start = *s;
	while (**s && **s != c)
		(*s)++;
	temp = ft_strndup(start, (*s - start));
	return (temp);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_count;
	char	**result;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc((word_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		result[i] = get_next_word(&s, c);
		if (result[i] == NULL)
			return (free_split_result(result));
		i++;
	}
	result[word_count] = NULL;
	return (result);
}

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int main()
// {
//     const char *input_string = "\0aaaa\0a";
//     char **result = ft_split(input_string, '\0');

// 	if (result == NULL)
// 	{
// 		printf("Memory allocation error\n");	
// 	}

// 	printf("Split Result:\n");
// 	for (int i = 0; result[i] != NULL; i++)
// 	{
// 		printf("'%s'\n", result[i]);
// 	}
//     free_split_result(result);
// }
