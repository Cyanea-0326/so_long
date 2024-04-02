/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:25:13 by shonakam          #+#    #+#             */
/*   Updated: 2023/11/02 21:41:29 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if ((base[i] <= 13 && base[i] >= 9) || base[i] == ' '
			|| base[i] == '+' || base[i] == '-')
			return (0);
		j = 0;
		while (base[i] != base[j])
		{
			j++;
		}
		if (i != j)
			return (0);
		i++;
	}
	return (i);
}

int	ft_putnbr_base(intmax_t nbr, char *base, int count)
{
	int			base_len;
	int			sign;
	long long	n;

	base_len = 0;
	n = nbr;
	if (is_valid_base(base) == 0)
		return (0);
	base_len += is_valid_base(base);
	sign = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n *= -1;
		sign += 1;
	}
	if (n >= base_len)
	{
		count += ft_putnbr_base(n / base_len, base, count);
		ft_putchar_fd(base[n % base_len], 1);
	}
	else
		ft_putchar_fd(base[n], 1);
	return (count += (1 + sign));
}
