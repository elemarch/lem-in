/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:55:48 by esaminad          #+#    #+#             */
/*   Updated: 2015/02/04 17:29:02 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isnumber(int c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}

int		ft_ishexc(int c)
{
	if (ft_isdigit((int)c) || (c >= 'A' || c <= 'F'))
		return (1);
	return (0);
}

int		ft_ishex(char *str)
{
	int	c;

	while (*str)
	{
		c = ft_toupper(*str);
		if (ft_ishexc(c))
			str++;
		else
			return (0);
	}
	return (1);
}

int		ft_ishex_color(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (*str && i < 6)
	{
		c = ft_toupper(*str);
		if (ft_isdigit((int)c) || (c >= 'A' || c <= 'F'))
			str++;
		else
			return (0);
		i++;
	}
	if (*str != '\0')
		return (0);
	return (1);
}
