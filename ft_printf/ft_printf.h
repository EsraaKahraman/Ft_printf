/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esrkahra <esrkahra@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 23:06:24 by esrkahra          #+#    #+#             */
/*   Updated: 2024/12/10 23:06:24 by esrkahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_hexa(unsigned int h, int c);
int	ft_printf(const char *format, ...);
int	ft_pointer(unsigned int *ptr);
int	ft_desript(char c, va_list args);
int	ft_putnbr(int n);
int	ft_uputnbr(unsigned int n);
#endif