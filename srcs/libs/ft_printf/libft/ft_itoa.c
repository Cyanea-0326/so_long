/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:06:00 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/04 21:10:20 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(int num)
{
	size_t	size;
	int		temp;

	size = 0;
	temp = num;
	if (num == 0)
		return (1);
	while (temp < 0)
	{
		size++;
		temp /= 10;
	}
	return (size);
}

static char	*allocate_arr(char *str, int n, int i)
{
	int	digit;

	if (n == 0)
	{
		str[0] = '0';
		return (str);
	}
	while (n != 0)
	{
		digit = n % 10;
		str[i] = -digit + '0';
		n /= 10;
		i--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		size;
	int		i;
	char	*str;

	sign = 1;
	if (0 <= n)
	{
		n = -n;
		sign = 0;
	}
	size = get_size(n);
	str = (char *)malloc((size + sign + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (sign)
		str[0] = '-';
	i = size + sign - 1;
	str = allocate_arr(str, n, i);
	str[size + sign] = '\0';
	return (str);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// int main(void)
// {
//     int numbers[] = {123, -456, 7890, 0, -12345, INT_MIN, INT_MAX};

//     for (int i = 0; i < sizeof(numbers) / sizeof(numbers[0]); ++i)
//     {
//         char *str = ft_itoa(numbers[i]);

//         if (str != NULL)
//         {
//             printf("Integer: %d\n", numbers[i]);
//             printf("String: %s\n", str);
//             free(str);
//         }
//         else
//         {
//             printf("Memory allocation failed.\n");
//         }
//     }
// }
