/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 04:49:27 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/04 15:07:22 by shonakam         ###   ########.fr       */
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

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// void	ft_putstr_fd(char *s, int fd)
// {
// 	write(fd, s, ft_strlen(s));
// }

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	else
	{
		if (0 > n)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

// #include "limits.h"
// int main(int ac, char **av)
// {
// 	int	fd = 1;
// 	ft_putnbr_fd(INT_MAX, fd);
// 	write(1, "\n", 1);
// 	ft_putnbr_fd(INT_MIN, fd);
// 	write(1, "\n", 1);
// 	if (ac == 2)
// 	{
// 		char *input = av[1];
// 		int num = atoi(input);
// 		printf("%s\n", input);
// 		ft_putnbr_fd(num, fd);
// 	}
// }
