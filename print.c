/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:50:00 by mnaouss           #+#    #+#             */
/*   Updated: 2025/06/17 01:25:14 by mnaouss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(const char *s)
{
	int	len;

	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

int	print_nbr(int n)
{
	int		count;
	long	nbr;

	count = 0;
	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		count++;
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		count += print_nbr(nbr / 10);
	}
	print_char((nbr % 10) + '0');
	count++;
	return (count);
}

int	print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += print_unsigned(n / 10);
	}
	print_char((n % 10) + '0');
	count++;
	return (count);
}

int	print_hex(unsigned int n, int uppercase)
{
	int		count;
	char	*base;

	count = 0;
	if (uppercase)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
	{
		count += print_hex(n / 16, uppercase);
	}
	print_char(base[n % 16]);
	count++;
	return (count);
}
