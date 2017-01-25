/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:44:57 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/10 17:49:57 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_filsize(char *fname)
{
	int		file;
	int		readfd;
	int		size;
	char	buff[1025];

	file = open(fname, O_RDONLY);
	readfd = 1;
	size = 0;
	while (readfd > 0)
	{
		readfd = read(file, buff, 1024);
		size += readfd;
	}
	close(file);
	return (size);
}
