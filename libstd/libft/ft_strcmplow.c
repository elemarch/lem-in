/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmplow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 07:53:03 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/27 01:56:08 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmplow(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (ft_tolower(s1[i]) == ft_tolower(s2[i]) && s1[i] != '\0')
		i++;
	i = (unsigned char)ft_tolower(s1[i]) - (unsigned char)ft_tolower(s2[i]);
	return (i);
}
