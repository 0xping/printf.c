/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:09:04 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/11/02 02:17:33 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int n, int u)
{
	long int	nb;
	int			len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		if (u)
			nb = (unsigned int)nb;
		else
		{
			nb *= -1;
			len += ft_putchar('-');
		}
	}
	if (nb >= 0 && nb <= 9)
	{
		len += ft_putchar(nb + '0');
	}
	else
	{
		len += ft_putnbr(nb / 10, u);
		len += ft_putchar(nb % 10 + '0');
	}
	return (len);
}

int	ft_putstr(char *s)
{
	int	i;
	int	len;

	len = 0;
	if (s)
	{
		i = 0;
		while (s[i])
		{
			len += ft_putchar(s[i]);
			i++;
		}
	}
	else
		len += ft_putstr("(null)");
	return (len);
}

int	ft_puthexnbr(unsigned long nb, char *base, int isLong)
{
	char	*result;
	char	*tmp;
	char	*remainder;
	int		len;

	if (!isLong)
		nb = (unsigned int)nb;
	if (nb == 0)
		return (ft_putchar('0'));
	result = ft_strdup("");
	while (nb)
	{
		remainder = to_str(base[nb % 16]);
		tmp = ft_strjoin(remainder, result);
		free(remainder);
		free(result);
		result = tmp;
		nb /= 16;
	}
	len = ft_putstr(result);
	free(result);
	return (len);
}

char	*to_str(char c)
{
	char	*str;

	str = malloc(2);
	str[0] = c;
	str[1] = 0;
	return (str);
}
