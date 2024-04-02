/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:24:28 by shonakam          #+#    #+#             */
/*   Updated: 2023/09/29 20:47:31 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*s_cpy;
	unsigned char	cast_c;

	cast_c = (unsigned char)c;
	s_cpy = (char *)s;
	while (*s_cpy != '\0' && *s_cpy != cast_c)
	{
		s_cpy++;
	}
	if (*s_cpy == cast_c)
		return ((char *)s_cpy);
	return (NULL);
}
