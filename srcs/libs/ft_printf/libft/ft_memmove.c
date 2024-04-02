/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 14:22:12 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/10 11:03:21 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_c;
	const char	*src_c;

	if (!dst && !src)
		return (NULL);
	dst_c = (char *)dst;
	src_c = (char *)src;
	if ((dst <= src && dst + len > src) || (src >= dst && src < dst + len))
	{
		while (len-- != 0)
			*dst_c++ = *src_c++;
	}
	else
	{
		dst_c += len;
		src_c += len;
		while (len-- != 0)
			*--dst_c = *--src_c;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char str[] = "abcde'fghijklmno'pqrstu";

// 	printf("移動前：%s\n", str);

// 	ft_memmove(str + 5, str, 10);

// 	printf("移動後：%s\n", str);
// }
