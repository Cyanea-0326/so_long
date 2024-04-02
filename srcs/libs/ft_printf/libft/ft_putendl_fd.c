/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 04:34:45 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/05 20:49:33 by shonakam         ###   ########.fr       */
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

// void	ft_putstr_fd(char *s, int fd)
// {
// 	write(fd, s, ft_strlen(s));
// }

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// int main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int	fd = 1;
// 		char *input = av[1];
// 		printf("%s\n", input);
// 		ft_putendl_fd(input, fd);
// 	}
// }