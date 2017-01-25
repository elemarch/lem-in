/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filcanread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:47:39 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/10 17:57:48 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_filcanread(char *fname)
{
	int		op;
	int		readfd;
	char	buff[2];

	op = open(fname, O_RDONLY);
	readfd = 0;
	if (op == -1)
		return (0);
	readfd = read(op, buff, 1);
	if (readfd == -1)
		return (0);
	if (close(op) == -1)
		return (0);
	return (1);
}
