/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:23:31 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/05 21:41:56 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (p);
}

// #include <stdio.h>
// #include <string.h>

// int	main()
// {
// 	char buf_a[] = "TEST_0000";
// 	char buf_b[] = "TEST_0000";

// 	ft_memset(buf_a+5, '9', 0);
// 	memset(buf_b+5, '9', 0);

// 	printf("ft is %s\n", buf_a);
// 	printf("uni is %s\n", buf_b);
// }
