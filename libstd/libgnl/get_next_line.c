/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/15 20:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/08/15 20:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "liblst.h"
#include "get_next_line.h"

static char	**get_fdbuff(int const fd)
{
	static t_list	*statl = NULL;
	t_list			*l;

	if (!statl)
	{
		statl = lst_n(ft_strdup(""), sizeof(char*));
		statl->content_size = fd;
	}
	l = statl;
	while (l)
	{
		if (fd == (int const)l->content_size)
			return ((char**)&(l->content));
		if (!l->next)
			break ;
		l = l->next;
	}
	l->next = lst_n(ft_strdup(""), sizeof(char*));
	l->next->content_size = fd;
	return ((char**)(&(l->next->content)));
}

static int	read_file(int const fd, char **buff)
{
	char	*b;
	int		r;

	if (!(b = (char*)malloc(sizeof(char) * FULL_BUFF)))
		return (-1);
	while (ft_bzero(b, FULL_BUFF), 1)
	{
		r = read((int)fd, b, BUFF_SIZE);
		if (r < 0)
			break ;
		else
		{
			*buff = ft_strfjoin((buff && *buff ? *buff : NULL), b);
			if (r == 0)
				break ;
			if (ft_strchr(*buff, '\n'))
				break ;
		}
	}
	FREE(b);
	if (r < 0)
		return (-1);
	else
		return (r > 0 ? 1 : 0);
}

static int	strip_line(char **line, char **buff, int r)
{
	char	*s;
	char	*tmp;

	s = NULL;
	if (!buff || !*buff || **buff == '\0')
		return (0);
	if (!(s = ft_strchr(*buff, '\n')))
	{
		if (r != 0)
			return (0);
		else
		{
			*line = ft_strdup(*buff);
			FREE(*buff);
			*buff = ft_strdup("");
			return (1);
		}
	}
	if (!(*line = ft_strnew(((size_t)(s - *buff)))))
		return (0);
	*line = ft_memcpy(*line, *buff, (s - *buff));
	tmp = ft_strdup(++s);
	FREE(*buff);
	*buff = tmp;
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	char	**buff;
	int		r;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!(buff = get_fdbuff(fd)))
		return (0);
	if (strip_line(line, buff, -1))
		return (1);
	r = read_file(fd, buff);
	if (r >= 0)
		strip_line(line, buff, r);
	return (r);
}
