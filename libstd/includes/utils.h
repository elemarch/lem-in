/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by esaminad          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# define TRUE		1
# define FALSE		0
# define INT32_MI	-2147483648
# define INT32_MX	2147483647

# define ISBLANK(x) (x == ' ' || x == '\t')
# define ISINT(x)	(x >= INT32_MI && x <= INT32_MX ? 1 : 0)

# define FREE(x)		{ if (x) free(x); x = NULL; }
# define RFREE(x)		{ if (x && *x) free(*x); *x = NULL; }
# define ABS(x)			((x >= 0) ? x : -(x))
# define BIG(x1, x2)	((x1 > x2) ? x1 : x2)
# define SMALL(x1, x2)	((x1 < x2) ? x1 : x2)
# define SQR(x)			(x * x)
# define SEG_SIZE(x1, x2, y1, y2) (SQR(x1 - x2) + SQR(y1 - y2))
# define CHAR_ISUPPER(x) (x >= 'A' && x <= 'Z' ? 1 : 0)
# define CHAR_ISLOWER(x) (x >= 'a' && x <= 'z' ? 1 : 0)

# define BLUE	0x0000cc
# define GREEN	0x00cc00
# define BROWN	0xcc6600
# define GRAY	0x999999
# define FUSHIA	0xcc00cc
# define YELLOW	0xcccc00
# define CYAN	0xccffff
# define WHITE	0xffffff
# define RED	0xff0000

/*
** Fake boolean, can be 0 or 1
** Since the computer canno allocate less than 4 bits in memory for a var
** it's useless to try to get less.
*/
typedef unsigned char	t_bool;

#endif
