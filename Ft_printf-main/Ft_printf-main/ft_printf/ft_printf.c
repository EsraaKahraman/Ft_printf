/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esrkahra <esrkahra@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:47:00 by esrkahra          #+#    #+#             */
/*   Updated: 2024/12/10 21:47:00 by esrkahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_desript(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_str(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		len += ft_uputnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		len += ft_hexa(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		len += ft_hexa(va_arg(args, unsigned int), 'X');
	else if (c == 'p')
	{
		if (va_arg(args, void *) == NULL)
			return (write(1,"(nil)", 5));
		len += ft_str("0x") + ft_p(va_arg(args, void *));
	}
	else if (c == '%')
		len += ft_putchar('%');
	else
		return (ft_putchar(c));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[++i])
				len += ft_desript(format[i], args);
		}
		else if (format[i] != '%')
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end (args);
	return (len);
}