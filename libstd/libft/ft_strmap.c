/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:46:29 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/07 16:13:22 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		size;
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	size = 0;
	i = 0;
	while (s[size] != '\0')
		size++;
	if ((str = (char *)malloc(size * sizeof(char))) == NULL)
		return (NULL);
	while (i < size && s[i] != '\0')
	{
		str[i] = (*f)(s[i]);
		i++;
	}
	return (str);
}
