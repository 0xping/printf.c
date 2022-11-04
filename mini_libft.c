/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:57:36 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/11/04 12:08:38 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*p;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	p = malloc(len + 1);
	i = 0;
	if (p)
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = 0;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;
	int		j;

	if (!s1 || !s2)
		return (0);
	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
	{
		i = 0;
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
		j = 0;
		while (s2[j])
		{
			result[i] = s2[j];
			j++;
			i++;
		}
		result[i] = 0;
	}
	return (result);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)s + i) = 0;
		i++;
	}
}
