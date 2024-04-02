/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:05:52 by shonakam          #+#    #+#             */
/*   Updated: 2023/11/02 20:42:13 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			total_len;

	total_len = 0;
	if (!format)
		return (0);
	va_start(args, format);
	total_len = count_total(format, args);
	va_end(args);
	return (total_len);
}

int	count_total(const char *s, va_list args)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] == '%')
		{
			index++;
			count += ft_switch_spec(s[index], args);
		}
		else
		{
			ft_putchar_fd(s[index], 1);
			count++;
		}
		index++;
	}
	return (count);
}
