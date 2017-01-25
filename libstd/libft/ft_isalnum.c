/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:53:27 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/03 15:55:19 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') ||
		(c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int		ft_isalnumstr(char *c)
{
	if (!c)
		return (0);
	while (*c)
	{
		if (!ft_isalnum(*c))
			return (0);
		c++;
	}
	return (1);
}

int		ft_isdigitstr(char *c)
{
	if (!c)
		return (0);
	while (*c)
	{
		if (!ft_isdigit(*c))
			return (0);
		c++;
	}
	return (1);
}

int		ft_isnumberstr(char *c)
{
	if (!c)
		return (0);
	while (*c)
	{
		if (!ft_isnumber(*c))
			return (0);
		c++;
	}
	return (1);
}
