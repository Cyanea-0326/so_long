/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 23:53:12 by shonakam          #+#    #+#             */
/*   Updated: 2023/10/17 04:22:11 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_string(char *str)
{
	int	count;

	if (str == NULL)
		str = "(null)";
	count = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (count);
}
