/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 05:40:55 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/20 12:37:26 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*stri;

	if (!s)
		return (NULL);
	if ((str = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	stri = str;
	while (start-- > 0)
		s++;
	while (len-- > 0)
		*stri++ = *s++;
	*stri = '\0';
	return (str);
}
