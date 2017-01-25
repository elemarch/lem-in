/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 05:41:56 by esaminad          #+#    #+#             */
/*   Updated: 2015/02/06 10:56:16 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_num_size(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			n++;
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	char			*s;
	int				sz;
	int				neg;
	unsigned int	num;

	sz = ft_get_num_size(n);
	neg = 0;
	if ((s = ft_strnew((size_t)(sz + 1))) == NULL)
		return (NULL);
	if (n < 0)
	{
		neg = 1;
		num = -n;
	}
	else
		num = n;
	sz--;
	while (sz >= 0)
	{
		s[sz--] = (num % 10) + '0';
		num /= 10;
	}
	if (neg)
		s[0] = '-';
	return (s);
}
