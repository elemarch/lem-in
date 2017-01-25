/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 05:41:33 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/10 22:43:40 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	unsigned int	st;
	unsigned int	end;
	char			*str;
	char			*sitr;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return ((char *)s);
	st = 0;
	end = (ft_strlen((char *)s) - 1);
	while (s[st] != '\0' &&
			(s[st] == ' ' || s[st] == '\n' || s[st] == '\t'))
		st++;
	while ((s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			&& end > 0 && end > st)
		end--;
	str = ft_strnew((end - st) + 1);
	sitr = str;
	while (st <= end)
		*sitr++ = s[st++];
	*sitr = '\0';
	return (str);
}
