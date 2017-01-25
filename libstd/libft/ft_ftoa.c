/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/06 10:33:01 by esaminad          #+#    #+#             */
/*   Updated: 2015/03/17 12:43:53 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_dectoi(float n, int prec)
{
	while (prec-- > 0)
		n *= 10;
	return (ft_ftoi(n));
}

static void	remove_trailing(char *str)
{
	int sz;

	if (!str)
		return ;
	sz = ft_strlen(str) - 1;
	while (sz > 0)
	{
		if (str[sz] && str[sz] == '0')
			str[sz] = '0';
		if (str[sz] == '\0')
		{
			sz--;
			continue ;
		}
		if (str[sz] != '\0' && str[sz] != '0')
			return ;
	}
}

int			ft_ftoi(float n)
{
	int i;

	if (n < -2147483648)
		return (-2147483648);
	if (n > 2147483647)
		return (2147483647);
	i = n;
	if (i > n)
		i--;
	return (i);
}

char		*ft_ftoa(float n, int prec)
{
	int		base;
	char	*p1;
	char	*p2;
	char	*r;
	char	*st;

	base = ft_ftoi(n);
	p1 = ft_itoa(base);
	p2 = ft_itoa(ft_dectoi(n - base, prec));
	remove_trailing(p2);
	r = ft_strnew(ft_strlen(p1) + ft_strlen(p2) + 2);
	st = r;
	while (*p1)
		*r++ = *p1++;
	*r++ = '.';
	while (*p2)
		*r++ = *p2++;
	*r = '\0';
	return (st);
}
