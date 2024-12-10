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
		len += ft_putchar('-');
		len += ft_putnbr(-n);
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
		len += ft_putchar(n + '0');
	return (len);
}

int	ft_hexa(unsigned int h, int c)
{
	char	*hexadecimal;
	int		len;

	hexadecimal = "0123456789abcdef";
	if (c == 'X')
		hexadecimal = "0123456789ABCDEF";
	len = 0;
	if (h >= 16)
		len += ft_hexa((h / 16), c);
	len += ft_putchar(hexadecimal[h % 16]);
	return (len);
}

int	ft_p(unsigned long a, int sign)
{
	int ret;

	ret = 0;
	if (sign == 1)
	{
		ret += write(1, "0x", 1);
		sign = 0;
	}
	if (a >= 16)
		ret 
}
