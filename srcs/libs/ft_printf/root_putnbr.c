/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   root_putnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:44:20 by shonakam          #+#    #+#             */
/*   Updated: 2023/11/11 17:54:57 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_edge(intmax_t nbr)
{
	if (nbr == (intmax_t)ULONG_MAX)
	{
		ft_putstr_fd("0xffffffffffffffff", 1);
		return (18);
	}
	if (nbr == (intmax_t)LONG_MAX)
	{
		ft_putstr_fd("0x7fffffffffffffff", 1);
		return (18);
	}
	if (nbr == (intmax_t)LONG_MIN)
	{
		ft_putstr_fd("0x8000000000000000", 1);
		return (18);
	}
	return (0);
}

int	root_putnbr(intmax_t nbr, char c, int output)
{
	char	*dec;
	char	*hexa;

	dec = "0123456789";
	hexa = "0123456789abcdef";
	if (c == 'p')
	{
		output += handle_edge(nbr);
		if (output)
			return (output);
	}
	if (c == 'i' || c == 'd' || c == 'u')
		output = ft_putnbr_base(nbr, dec, output);
	else if (c == 'p' || c == 'x' || c == 'X')
	{
		if (c == 'p')
			output += format_string("0x");
		else if (c == 'X')
			hexa = "0123456789ABCDEF";
		output += ft_putnbr_base(nbr, hexa, 0);
	}
	return (output);
}
