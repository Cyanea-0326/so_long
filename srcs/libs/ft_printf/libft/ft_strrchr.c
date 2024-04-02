/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:41:40 by shonakam          #+#    #+#             */
/*   Updated: 2023/09/29 20:49:28 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*s_cpy;
	unsigned char	cast_c;

	s_cpy = s;
	cast_c = (unsigned char)c;
	while (*s_cpy != '\0')
		s_cpy++;
	while (s < s_cpy && *s_cpy != cast_c)
	{
		s_cpy--;
	}
	if (*s_cpy == cast_c)
		return ((char *)s_cpy);
	return (NULL);
}
