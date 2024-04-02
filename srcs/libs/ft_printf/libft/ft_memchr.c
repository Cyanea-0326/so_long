/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 02:41:38 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/05 21:44:36 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;
	unsigned char	cast_c;

	s_tmp = (unsigned char *)s;
	cast_c = (unsigned char)c;
	while (n)
	{
		if (*s_tmp == cast_c)
			return (s_tmp);
		s_tmp++;
		n--;
	}
	return (NULL);
}

// int main() {
//     // テストケース1: 文字列から特定の文字を検索
//     char str = NULL;
//     char target = 'W';
//     size_t n = strlen(str);
//     void *result = ft_memchr(str, target, n);

//     if (result != NULL) {
//         printf("Character '%c' found at position: 
// %ld\n", target, (char *)result - str);
//     } else {
//         printf("Character '%c' not found in the string.\n", target);
//     }

//     // テストケース2: バッファから特定の数値を検索
//     int numbers[] = {1, 2, 3, 4, 5};
//     int num_to_find = 3;
//     n = sizeof(numbers) / sizeof(numbers[0]);
//     result = ft_memchr(numbers, num_to_find, n * sizeof(int));

//     if (result != NULL) {
//         printf("Number %d found at position: 
// %ld\n", num_to_find, (int *)result - numbers);
//     } else {
//         printf("Number %d not found in the array.\n", num_to_find);
//     }
// }