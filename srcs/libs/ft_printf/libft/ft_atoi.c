/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:36:27 by shonakam          #+#    #+#             */
/*   Updated: 2024/03/26 03:00:48 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	solve_long(const char *str, int sign)
{
	long long	res;

	res = 0;
	while (*str != '\0' && ('0' <= *str && *str <= '9'))
	{
		if (res > (LONG_MAX - (*str - '0')) / 10)
		{
			if (sign == 1)
				return ((int)(LONG_MAX));
			else
				return ((int)(LONG_MIN));
		}
		res = (res * 10) + (*str - '0');
		str++;
	}
	return ((int)(sign * res));
}

int	ft_atoi(const char *str)
{
	int		flag;

	flag = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	return (solve_long(str, flag));
}

// int	main(int ac, char **av)
// {
// 	if (ac == 2)
// 	{
// 		int	res1 = ft_atoi(av[1]);
// 		int	res2 = atoi(av[1]);
// 		printf("ft :'%d'\n", res1);
// 		printf("uni:'%d'\n", res2);
// 	}
// }
