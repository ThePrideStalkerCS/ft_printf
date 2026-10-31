/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftput.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maratana <maratana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 22:31:34 by maratana          #+#    #+#             */
/*   Updated: 2026/10/31 18:05:08 by maratana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	long	l;
	char	c;

	l = n;
	count = 1;
	if (l < 0)
	{
		l *= -1;
		write(fd, "-", 1);
		count++;
	}
	if (l > 9)
	{
		count += ft_putnbr_fd(l / 10, fd);
		ft_putnbr_fd(l % 10, fd);
	}
	else
	{
		c = l + '0';
		write(fd, &c, 1);
	}
	return (count);
}

int	ft_putuint_fd(unsigned int n, int fd)
{
	int		count;
	char	c;

	count = 1;
	if (n > 9)
	{
		count += ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		c = n + '0';
		write(fd, &c, 1);
	}
	return (count);
}

int	ft_putpointer(void *p)
{
	uintptr_t	i;

	if (!p)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	i = (uintptr_t)p;
	write(1, "0x", 2);
	return (pointerhex(i) + 2);
}
