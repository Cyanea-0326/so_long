/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch_spec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:12:17 by shonakam          #+#    #+#             */
/*   Updated: 2023/11/02 21:38:17 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_switch_spec(char c, va_list args)
{
	int	output;

	output = 0;
	if (c == 'c')
		output = format_char(va_arg(args, int));
	else if (c == 's')
		output = format_string(va_arg(args, char *));
	else if (c == 'p')
		output = root_putnbr(va_arg(args, unsigned long long), c, output);
	else if (c == 'u' || c == 'x' || c == 'X')
		output = root_putnbr(va_arg(args, unsigned int), c, output);
	else if (c == 'd' || c == 'i')
		output = root_putnbr(va_arg(args, int), c, output);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (output);
}
