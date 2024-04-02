/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shonakam <shonakam@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:06:13 by shonakam          #+#    #+#             */
/*   Updated: 2023/11/11 18:05:37 by shonakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <limits.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		count_total(const char *s, va_list args);
// formats
int		format_char(char c);
int		format_string(char *str);
int		root_putnbr(intmax_t nbr, char c, int output);
int		ft_putnbr_base(intmax_t nbr, char *base, int count);
int		ft_switch_spec(char c, va_list args);

#endif