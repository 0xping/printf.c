/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 16:31:54 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/11/05 15:18:13 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_specifier2(char sp, va_list list, char *prefix)
{
	int				len;
	unsigned int	tmp;

	len = 0;
	tmp = 0;
	if (sp == 'X' || sp == 'x')
	{
		tmp = va_arg(list, unsigned int);
		if (prefix[2] == '#' && tmp != 0)
		{
			len += ft_putchar('0');
			len += ft_putchar(sp);
		}
		(sp == 'X') && (len += ft_puthexnbr(tmp, "0123456789ABCDEF", 0));
		(sp == 'x') && (len += ft_puthexnbr(tmp, "0123456789abcdef", 0));
	}
	else if (sp == 'p')
	{
		len += ft_putstr("0x");
		len += ft_puthexnbr(va_arg(list, unsigned long), "0123456789abcdef", 1);
	}
	(sp == 'u') && (len += ft_putnbr(va_arg(list, int), 1));
	(sp == 'c') && (len += ft_putchar((char)va_arg(list, int)));
	return (len);
}

static int	ft_print_specifier(char sp, va_list list, char *prefix)
{
	int		len;
	long	tmp;

	len = 0;
	if (sp == 'd' || sp == 'i')
	{
		tmp = va_arg(list, int);
		if (tmp >= 0)
		{
			if (prefix[1] == ' ' && prefix[0] != '+')
				len += ft_putchar(' ');
			if (prefix[0] == '+')
				len += ft_putchar('+');
		}
		len += ft_putnbr(tmp, 0);
	}
	else if (sp == 's')
		len += ft_putstr(va_arg(list, char *));
	else if (sp == 'x' || sp == 'X' || sp == 'p' || sp == 'u' || sp == 'c')
		len += ft_print_specifier2(sp, list, prefix);
	else
		len += ft_putchar(sp);
	return (len);
}

void	get_prefix(const char *str, int *i, char *prefix)
{
	while (str[*i + 1] == '+' || str[*i + 1] == ' ' || str[*i + 1] == '#')
	{
		if (str[*i + 1] == '+')
			prefix[0] = '+';
		if (str[*i + 1] == ' ')
			prefix[1] += ' ';
		if (str[*i + 1] == '#')
			prefix[2] += '#';
		*i += 1;
	}
}

static void	print(const char *str, va_list list, int *len)
{
	int		i;
	char	prefix[3];

	ft_bzero(prefix, 3);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			get_prefix(str, &i, prefix);
			if (prefix[0] + prefix[1] + prefix[2] != 0 && !str[i + 1])
				break ;
			*len += ft_print_specifier(str[i + 1], list, prefix);
			ft_bzero(prefix, 3);
			i++;
		}
		else
			*len += ft_putchar(str[i]);
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		len;

	len = 0;
	va_start(list, str);
	print(str, list, &len);
	va_end(list);
	return (len);
}
