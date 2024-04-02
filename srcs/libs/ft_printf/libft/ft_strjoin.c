/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:58:52 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/04 15:11:42 by shonakam         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	char	*str_dest;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_dest = (char *)malloc((s1_len + s2_len) * sizeof(char) + 1);
	if (str_dest == NULL)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		str_dest[i++] = *s1++;
	}
	while (*s2)
	{
		str_dest[i++] = *s2++;
	}
	str_dest[i] = '\0';
	return (str_dest);
}

// int main()
// {
//     // テストケース1: 2つの文字列を連結する
//     const char *s1 = "Hello, ";
//     const char *s2 = "world!";
//     char *result1 = ft_strjoin(s1, s2);
//     if (result1 != NULL)
//     {
//         printf("Test case 1: %s\n", result1);
//         free(result1); // メモリ解放
//     }
//     else
//     {
//         printf("Test case 1: Memory allocation failed\n");
//     }

//     // テストケース2: 1つ目の文字列が空の場合
//     const char *s3 = "";
//     char *result2 = ft_strjoin(s3, s2);
//     if (result2 != NULL)
//     {
//         printf("Test case 2: %s\n", result2);
//         free(result2);
//     }
//     else
//     {
//         printf("Test case 2: Memory allocation failed\n");
//     }

//     // テストケース3: 2つ目の文字列が空の場合
//     const char *s4 = "Hello, ";
//     const char *s5 = "";
//     char *result3 = ft_strjoin(s4, s5);
//     if (result3 != NULL)
//     {
//         printf("Test case 3: %s\n", result3);
//         free(result3);
//     }
//     else
//     {
//         printf("Test case 3: Memory allocation failed\n");
//     }

//     // テストケース4: 両方の文字列が空の場合
//     const char *s6 = "";
//     const char *s7 = "";
//     char *result4 = ft_strjoin(s6, s7);
//     if (result4 != NULL)
//     {
//         printf("Test case 4: %s\n", result4);
//         free(result4);
//     }
//     else
//     {
//         printf("Test case 4: Memory allocation failed\n");
//     }

// 	// テストケース4: 両方の文字列が空の場合
//     const char *s8 = NULL;
//     const char *s9 = NULL;
//     char *result5 = ft_strjoin(s8, s9);
//     if (result5 == NULL)
//     {
//         printf("Test case 5: %s\n", result5);
//         free(result5);
//     }
//     else
//     {
//         printf("Test case 5: Memory allocation failed\n");
//     }
// }
