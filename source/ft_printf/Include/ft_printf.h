/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhusieva <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:10:27 by yhusieva          #+#    #+#             */
/*   Updated: 2024/01/22 14:10:29 by yhusieva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

int	ft_printf(const char *fmt, ...);
int	ft_conversions(const char type, va_list arg);

// cspdiuxX%:
int	ft_char(int c);
int	ft_string(char *s);
int	ft_number(int n);
int	ft_pointer(void *arr);
int	ft_unsigned_dec(unsigned int num);
int	ft_hexadecimal(unsigned int num, const char type, int count);
int	ft_percent(void);

int	ft_hex_base(int num);

#endif