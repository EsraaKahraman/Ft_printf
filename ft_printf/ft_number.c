/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esrkahra <esrkahra@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 21:36:32 by esrkahra          #+#    #+#             */
/*   Updated: 2024/12/10 21:36:32 by esrkahra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numdigit(int digit)
{
	int	i;

	i = 0;
	if (digit <= 0)
		i++;
	while (digit)
	{
		digit /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int	len;
	int	real_len;

	real_len = ft_numdigit(n);
	len = 0;
	if (n == -2147483648)
		len += write(1, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
		len += ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n > 9)
	{
		len += ft_putnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else
		len += ft_putchar(n + '0');
	if (real_len != len)
		return (-1);
	return (len);
}

int	ft_uputnbr(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
	{
		len += ft_uputnbr(n / 10);
		len += ft_putchar(n % 10 + '0');
	}
	else if (n <= 9)
		ft_putchar(n + '0');
	return (len);
}

int	ft_hexa(unsigned int h, int c)
{
	char	*hexadecimal;
	int		len;

	if (c == 'x')
		hexadecimal = "0123456789abcdef";
	else if (c == 'X')
		hexadecimal = "0123456789ABCDEF";
	len = 0;
	if (h >= 16)
		len += ft_hexa((h / 16), c);
	len += ft_putchar(hexadecimal[h % 16]);
	return (len);
}

int	ft_pointer(unsigned int *ptr)
{
	int		len;
	long	x;

	x = (long)ptr;
	len = 0;
	if (ptr == NULL)
	{
		len += write(1, "(nil)", 5);
		if (len == -1)
			return (-1);
	}
	while (ptr)
	{
		len += ft_hexa(x, 'x');
		if (len == -1)
			return (-1);
	}
	return (len);
}
