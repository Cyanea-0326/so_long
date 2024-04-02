/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:33:57 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/05 20:38:38 by shonakam         ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(s1);
	dup = (char *)malloc(len * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	dup[len] = '\0';
	while (len--)
	{
		dup[len] = s1[len];
	}
	return (dup);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // ft_strdup 関数の宣言
// char *ft_strdup(const char *s1);

// int main() {
//     const char *original = "Hello, world!"; // テスト対象の文字列

//     // テストケース1: 正常な文字列の複製
//     char *duplicate1 = ft_strdup(original);
//     if (duplicate1 != NULL) {
//         printf("Duplicate 1: '%s'\n", duplicate1);
//         free(duplicate1);
//     } else {
//         printf("Test case 1: Memory allocation failed\n");
//     }

//     // テストケース2: 空文字列の複製
//     const char *empty_str = "";
//     char *duplicate2 = ft_strdup(empty_str);
//     if (duplicate2 != NULL) {
//         printf("Duplicate 2: '%s'\n", duplicate2);
//         free(duplicate2);
//     } else {
//         printf("Test case 2: Memory allocation failed\n");
//     }

//     // テストケース3: NULL ポインタの複製 (エラー処理)
//     const char *null_str = NULL;
//     char *duplicate3 = ft_strdup(null_str);
//     if (duplicate3 != NULL) {
//         printf("Duplicate 3: %s\n", duplicate3);
//         free(duplicate3);
//     } else {
//		printf("Test case 3: failed (expected behavior)\n");
//     }
// }