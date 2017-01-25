/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 05:41:44 by esaminad          #+#    #+#             */
/*   Updated: 2014/12/07 16:20:32 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_wcount(char *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
			j = 0;
		else
		{
			if (j == 0)
			{
				i++;
				j = 1;
			}
		}
		s++;
	}
	return (i);
}

static char		*ft_strsplit_wd(char *s, int start, int end)
{
	char	*str;
	int		i;

	i = 0;
	if ((str = ft_strnew(end - start)) == NULL)
		return (NULL);
	while (start < end)
	{
		str[i++] = s[start];
		start++;
	}
	return (str);
}

static int		ft_strsplit_wend(char *s, int pos, char c)
{
	while (s[pos] != c)
	{
		if (s[pos] == '\0')
			break ;
		pos++;
	}
	return (pos);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	char	**begin;
	int		wcount;
	int		i;
	int		j;

	i = 0;
	wcount = get_wcount((char *)s, c);
	if ((arr = (char **)malloc(sizeof(char **) * wcount + 1)) == NULL)
		return (NULL);
	begin = arr;
	while (wcount-- > 0)
	{
		while (s[i] == c)
			i++;
		j = ft_strsplit_wend((char *)s, i, c);
		*arr++ = ft_strsplit_wd((char *)s, i, j);
		i = j;
	}
	*arr = 0;
	return (begin);
}

void			ft_strsplit_free(char **arr)
{
	char *str;

	if (!arr || !*arr)
		return ;
	while (arr)
	{
		str = *arr;
		if (str)
			FREE(str);
		arr++;
	}
}
