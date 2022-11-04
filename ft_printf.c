/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:31:54 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/11/03 19:35:52 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_specifier(char sp, va_list list)
{
	int	len;

	len = 0;
	if (sp == 'c')
		len += ft_putchar((char)va_arg(list, int));
	else if (sp == 'd' || sp == 'i')
		len += ft_putnbr(va_arg(list, int), 0);
	else if (sp == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (sp == 'u')
		len += ft_putnbr(va_arg(list, int), 1);
	else if (sp == 'x')
		len += ft_puthexnbr(va_arg(list, unsigned int), "0123456789abcdef", 0);
	else if (sp == 'X')
		len += ft_puthexnbr(va_arg(list, unsigned int), "0123456789ABCDEF", 0);
	else if (sp == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthexnbr(va_arg(list, unsigned long), "0123456789abcdef", 1);
	}
	else if (sp == '%')
		len += ft_putchar('%');
	else
		len += ft_putchar(sp);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		len;

	len = 0;
	va_start(list, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += print_specifier(str[i + 1], list);
			i++;
		}
		else
			len += ft_putchar(str[i]);
		i++;
	}
	return (len);
}
