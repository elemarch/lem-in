/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/01 19:53:39 by elemarch          #+#    #+#             */
/*   Updated: 2015/09/01 19:53:41 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

SDL_Rect	*img_defrect(int h, int w, int x, int y)
{
	SDL_Rect	*rect;

	rect = (SDL_Rect*)malloc(sizeof(SDL_Rect));
	if (h > -1)
		rect->h = h;
	if (w > -1)
	rect->w = w;
	if (x > -1)
	rect->x = x;
	if (y > -1)
	rect->y = y;
	return (rect);
}

void		img_put(t_sdl *sdl, int id, int x, int y)
{
	SDL_Rect	*dest;

	dest = img_defrect(0, 0, x, y);
	SDL_BlitSurface(sdl->imgs[id]->sur, sdl->imgs[id]->zone, sdl->screen, dest);
	FREE(dest);
}

void		img_putstr(t_sdl *sdl, char *str, int x, int y)
{
	int		i;

	i = 0;
	while (str[i])
	{
		sdl->imgs[BMP_CHAR]->zone = img_defrect(16, 16, str[i] - '0', 0);
		img_put(sdl, BMP_CHAR, x, y);
		x += 16;
		i++;
	}
}

void		img_load(t_sdl *sdl, int id, char *path, Uint32 trsp)
{
	t_img	*new_img;

	new_img = (t_img*)malloc(sizeof(t_img));
	new_img->id = id;
	new_img->zone = NULL;
	new_img->path = ft_strdup(path);
	new_img->sur = SDL_LoadBMP(path);
	new_img->sur->format->Amask = 0xFF000000;
	new_img->sur->format->Ashift = 24;
	SDL_SetColorKey(new_img->sur, SDL_SRCCOLORKEY, trsp);
	dlst_push_back_c(sdl->imglst, new_img, sizeof(new_img));
}

void		img_list(t_sdl *sdl)
{
	sdl->imglst = dlst_new();
	img_load(sdl, BMP_ANTS, IMG_ANTS, TRANSP);
	img_load(sdl, BMP_MENU, IMG_MENU, TRANSP);
	img_load(sdl, BMP_NEMPTY, IMG_NEMPTY, TRANSP);
	img_load(sdl, BMP_NEND, IMG_NEND, TRANSP);
	img_load(sdl, BMP_NLINK, IMG_NLINK, TRANSP);
	img_load(sdl, BMP_NROOM, IMG_NROOM, TRANSP);
	img_load(sdl, BMP_NSTART, IMG_NSTART, TRANSP);
	img_load(sdl, BMP_CHAR, IMG_CHAR, TRANSP);
	sdl->imgs = (t_img **)dlst_to_array(sdl->imglst);
	sdl->imgs[BMP_CHAR]->zone = img_defrect(16, 16, 0, 0);
	sdl->imgs[BMP_ANTS]->zone = img_defrect(32, 32, 0, 0);
}
