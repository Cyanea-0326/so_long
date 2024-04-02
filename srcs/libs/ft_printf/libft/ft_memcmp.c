/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 03:35:25 by shonakam          #+#    #+#             */
/*   Updated: 2023/09/29 19:38:07 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;

	buf1 = (unsigned char *)s1;
	buf2 = (unsigned char *)s2;
	while (n != 0)
	{
		if (*buf1 != *buf2)
			return (*buf1 - *buf2);
		buf1++;
		buf2++;
		n--;
	}
	return (0);
}
