/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 14:24:38 by maratana          #+#    #+#             */
/*   Updated: 2026/10/30 16:04:11 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

int	puthex(unsigned int n)
{
	char	*set;
	int		count;

	set = "0123456789abcdef";
	count = 1;
	if (n >= 16)
	{
		count += puthex(n / 16);
		puthex(n % 16);
	}
	else
	{
		write(1, &set[n], 1);
	}
	return (count);
}

int	put_hex(unsigned int n)
{
	char	*set;
	int		count;

	set = "0123456789ABCDEF";
	count = 1;
	if (n >= 16)
	{
		count += put_hex(n / 16);
	}
	write(1, &set[n % 16], 1);
	return (count);
}

int	pointerhex(uintptr_t n)
{
	char	*set;
	int		count;

	set = "0123456789abcdef";
	count = 1;
	if (n >= 16)
	{
		count += pointerhex(n / 16);
		pointerhex(n % 16);
	}
	else
	{
		write(1, &set[n], 1);
	}
	return (count);
}

int	format(char c, va_list *args, int chars)
{
	if (c == 'c')
		chars += ft_putchar_fd(va_arg(*args, int), 1);
	if (c == 's')
		chars += ft_putstr_fd(va_arg(*args, char *), 1);
	if (c == 'p')
		chars += ft_putpointer(va_arg(*args, void *));
	if (c == 'd')
		chars += ft_putnbr_fd(va_arg(*args, int), 1);
	if (c == 'i')
		chars += ft_putnbr_fd(va_arg(*args, int), 1);
	if (c == 'u')
		chars += ft_putuint_fd(va_arg(*args, unsigned int), 1);
	if (c == 'x')
		chars += puthex(va_arg(*args, unsigned int));
	if (c == 'X')
		chars += put_hex(va_arg(*args, unsigned int));
	if (c == '%')
		chars += write(1, "%", 1);
	return (chars);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		chars;
	va_list	args;

	va_start(args, s);
	i = 0;
	chars = 0;
	while (s[i])
	{
		if (s[i] != '%')
		{
			write(1, &s[i], 1);
			i++;
			chars++;
		}
		else
		{
			i++;
			chars = format(s[i], &args, chars);
			i++;
		}
	}
	va_end(args);
	return (chars);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char *p=0;
// 	printf("test? %p\n",p);
// 	printf("\nchars printed:%i",ft_printf("p adress: %p",p));
// }

// %c Prints a single character.
// %s Prints a string (as defined by the common C convention).
// %p The void * pointer argument has to be printed in hexadecimal format.
// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.
// %u Prints an unsigned decimal (base 10) number.
// %x Prints a number in hexadecimal (base 16) lowercase format.
// %X Prints a number in hexadecimal (base 16) uppercase format.
// %% Prints a percent sign.