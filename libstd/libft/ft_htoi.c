/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:04:52 by esaminad          #+#    #+#             */
/*   Updated: 2015/03/17 12:44:22 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	h_to_i(char c)
{
	if (!ft_ishexc(c))
		return (-1);
	if (ft_isdigit(c))
		return (c - '0');
	if (c == 'A')
		return (10);
	if (c == 'B')
		return (11);
	if (c == 'C')
		return (12);
	if (c == 'D')
		return (13);
	if (c == 'E')
		return (14);
	if (c == 'F')
		return (15);
	return (-1);
}

int			ft_htoi(const char *str)
{
	int	s;
	int	r;

	if (!str || !*str)
		return (0);
	s = ft_strlen((char *)str);
	if (!ft_ishex((char *)str))
		return (0);
	r = 0;
	while (*str)
		r += h_to_i(*str++) * ft_pow(16, --s);
	return (r);
}
