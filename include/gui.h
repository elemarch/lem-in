/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by elemarch          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GUI_H
# define GUI_H

/*
** === MACROS =============================================================== **
*/

/*
** --- bmp paths ----------------
*/

# define IMG_ANTS       "./rsc/ants.bmp"
# define IMG_MENU       "./rsc/menu.bmp"
# define IMG_NEMPTY     "./rsc/node_empty.bmp"
# define IMG_NEND       "./rsc/node_end.bmp"
# define IMG_NLINK      "./rsc/node_link.bmp"
# define IMG_NROOM      "./rsc/node_room.bmp"
# define IMG_NSTART     "./rsc/node_start.bmp"
# define IMG_CHAR       "./rsc/ascii.bmp"

/*
** --- KEYS ---------------------
*/

# define KEY            (sdl.event.key.keysym.sym)
# define CROSS_CLICK    (sdl.event.type == SDL_QUIT)
# define KEYDOWN        (sdl.event.type == SDL_KEYUP)
# define KEY_ESC        (KEY == SDLK_ESCAPE)
# define KEY_SPACE      (KEY == SDLK_SPACE)

/*
** --- COLORS -------------------
*/

# define TRANSP         0xCF00FF00

/*
** --- DIMENSIONS ---------------
*/

# define WIN_W          832
# define WIN_H          576
# define WIN_G			64

/*
** --- SPRITESHEET --------------
*/

# define SPRITE_W       32
# define SPRITE_H       32

/*
** === STRCTURES ============================================================ **
*/

enum            e_bmps
{
	BMP_MIN = -1,
	BMP_ANTS,
	BMP_MENU,
	BMP_NEMPTY,
	BMP_NEND,
	BMP_NLINK,
	BMP_NROOM,
	BMP_NSTART,
	BMP_CHAR,
	BMP_MAX
};


/*
** --- t_img --------------------
**  id      : image id
**  sur     : image SDL_Surface variable
**  trsp    : color of transparency
**  zone    : size of printed zone
** ------------------------------
*/

typedef struct  s_img
{
	int         id;
	SDL_Surface *sur;
	Uint32      trsp;
	SDL_Rect    *zone;
	char        *path;
}               t_img;

/*
** --- t_sdl --------------------
**  frame   : current frame
**  screen  : screen variable
**  event   : event variable
**  imgs    : pointer to a list of all images
** ------------------------------
*/

typedef struct  s_sdl
{
	int         frame;
	SDL_Surface *screen;
	SDL_Event   event;
	t_dlst      *imglst;
	t_img       **imgs;
}               t_sdl;

/*
** === PROTOTYPES === see main.h under section GUI PROTOTYPES line 98 ======= **
*/



#endif
