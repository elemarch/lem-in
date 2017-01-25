/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:56:50 by esaminad          #+#    #+#             */
/*   Updated: 2015/02/06 11:16:26 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

# include "utils.h"

/*
** ft_isalnum
** Return 1 if the given char is alphanumeric (min, maj, 0-9)
** --------------------
** ft_isalnumstr
** Return 1 if the given char *is alphanumeric (min, maj, 0-9)
*/
int					ft_isalnum(int	c);
int					ft_isalnumstr(char *c);

/*
** ft_isascii
** Return 1 if the given char an ascii char (0 to 127)
** --------------------
** ft_isprint
** Return 1 if the given char is printable (32 to 127)
** --------------------
** ft_isalpha
** Return 1 if the given char is alphabetic (min, maj)
*/
int					ft_isascii(int	c);
int					ft_isprint(int	c);
int					ft_isalpha(int	c);

/*
** ft_isdigit
** Return 1 if the given char is numeric (0-9)
** --------------------
** ft_isdigitstr
** Return 1 if the given char *is numeric (0-9)
** --------------------
** ft_isnumber
** Return 1 if the given char is numeric (0-9, '+', '-')
** --------------------
** ft_isnumberstr
** Return 1 if the given char *is numeric (0-9, '+', '-')
** --------------------
** ft_isnum
** Return 1 if the given char *is numeric (0-9, '+', '-')
*/
int					ft_isdigit(int	c);
int					ft_isdigitstr(char *c);
int					ft_isnumber(int	c);
int					ft_isnumberstr(char *c);
int					ft_isnum(char *str);

/*
** ft_ishexc
** Return 1 if the given char is hexadecimal (0-9, ABCDEF)
** --------------------
** ft_ishex
** Return 1 if the given char *is hexadecimal (0-9, (ABCDEF || abcdef))
** --------------------
** ft_ishex_color
** Return 1 if the given char *is 6 hex char long
*/
int					ft_ishexc(int c);
int					ft_ishex(char *str);
int					ft_ishex_color(char *str);

/*
** ft_strlen
** Return the number of char in the given char*, excluding the trailing \0
*/
size_t				ft_strlen(char *str);
size_t				ft_strlenc(char *str, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strcmplow(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmpw(char *s1, char *s2);

int					ft_tolower(int c);
int					ft_toupper(int c);

char				*ft_strdup(const char *s1);
char				*ft_strdups(const char *s1, size_t *sz);
void				*ft_memdup(void *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

int					ft_intsize(int n);
int					ft_abs(int nbr);
int					ft_pow(int nbr, int pow);
int					ft_atoi(const char *str);
int					ft_htoi(const char *str);
int					ft_ftoi(float n);
char				*ft_ftoa(float n, int prec);

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_swap(void *p1, void *p2);

void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putmstr(char *before, char *str, char *after);
void				ft_putcstr(char *str, char *color);
void				ft_putendl(char const *s);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);

void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strfjoin(char *s1, char *s2);
char				*ft_strmerge(char *dst, char *src, size_t at);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strsplit_free(char **arr);
char				*ft_itoa(int n);
char				*ft_strrepl(char *src, char *from, char *to);

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

void				ft_printarr(char **arr);

int					ft_filsize(char *fname);
int					ft_filcanread(char *fname);
char				*ft_filreadall(char *fname);
int					ft_fileopen(char *fname);

#endif
