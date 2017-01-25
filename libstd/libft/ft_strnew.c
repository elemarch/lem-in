/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:23:19 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/10 22:36:31 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;
	char *s;

	if ((int)size < 0)
		return (NULL);
	if ((str = (char *)malloc(size + 1 * sizeof(char))) == NULL)
		return (NULL);
	s = str;
	while (size-- > 0)
		*s++ = '\0';
	*s = '\0';
	return (str);
}
