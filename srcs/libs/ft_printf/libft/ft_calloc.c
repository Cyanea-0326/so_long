/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:37:24 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/10 10:09:56 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*sec_mem;

	if (count == 0 || size == 0)
		total_size = 1;
	else if ((size_t)SIZE_MAX / size < count)
		return (NULL);
	else
		total_size = (count * size);
	sec_mem = (void *)malloc(total_size);
	if (sec_mem == NULL)
		return (NULL);
	ft_memset(sec_mem, 0, total_size);
	return ((void *)sec_mem);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main() {
//     // テストケース1: countとsizeが正常な場合
//     // size_t count1 = 20;
//     // size_t size1 = sizeof(int);

// 	printf("%lu\n", (size_t)SIZE_MAX / 10 + (size_t)1);

//     int *array1 = (int *)ft_calloc((size_t)SIZE_MAX / 10 + (size_t)1, 10);

//     if (array1 != NULL) {
//         for (size_t i = 0; i < 10 + (size_t)1; i++) {
//             printf("%d ", array1[i]);
//         }
//         printf("\n");
//         free(array1);
//     } else {
//         printf("Test case 1: Failed to allocate memory\n");
//     }

//     // テストケース2: countがゼロの場合
//     size_t count2 = 0;
//     size_t size2 = sizeof(double);
//     double *array2 = (double *)ft_calloc(count2, size2);

//     if (array2 != NULL) {
//         // ゼロ要素の配列が割り当てられていることを確認
//         printf("Test case 2: Successfully allocated memory\n");
//         free(array2);
//     } else {
//         printf("Test case 2: Failed to allocate memory\n");
//     }

//     // テストケース3: sizeがゼロの場合
//     size_t count3 = 3;
//     size_t size3 = 0;
//     void *array3 = ft_calloc(count3, size3);

//     if (array3 != NULL) {
//         // ゼロバイトのメモリが割り当てられていることを確認
//         printf("Test case 3: Successfully allocated memory\n");
//         free(array3);
//     } else {
//         printf("Test case 3: Failed to allocate memory\n");
//     }
// }
