/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:12:28 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/05 21:41:49 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_c;
	char	*src_c;

	if ((!dst && !src) && n > 0)
		return (NULL);
	dst_c = (char *)dst;
	src_c = (char *)src;
	if (n == 0)
		return (dst);
	i = 0;
	while (i < n)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char d[] = "0123456789";
// 	char s[] = "abc";

// 	printf("%s\n", ft_memcpy(d, s, 2));
// 	//printf("%s\n", memcpy(d, s,2));
// }
