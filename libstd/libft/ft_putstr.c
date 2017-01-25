/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:52:44 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/27 09:24:36 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	while (*s != '\0')
		write(1, s++, 1);
	write(1, "\0", 1);
}

void	ft_putmstr(char *before, char *str, char *after)
{
	ft_putstr(before);
	ft_putstr(str);
	ft_putstr(after);
}
