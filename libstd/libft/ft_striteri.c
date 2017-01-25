/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esaminad <esaminad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:36:36 by esaminad          #+#    #+#             */
/*   Updated: 2014/11/07 16:11:31 by esaminad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;
	unsigned int j;

	if (!s || !f)
		return ;
	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	while (j < i)
		(*f)(j++, s++);
}
