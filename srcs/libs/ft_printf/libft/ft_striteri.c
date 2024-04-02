/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 03:30:43 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/04 15:35:50 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, (s + i));
		i++;
	}
}

////////////////////////////////////

// void	ft_test_toupper(unsigned int index, char *c)
// {
// 	(void)index;

// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - ('a' - 'A');
// }

// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		char *input = av[1];
// 		printf("Original: %s\n", input);
// 		ft_striteri(input, ft_test_toupper);
// 		printf("Transformed: %s\n", input);
// 	}
// }
