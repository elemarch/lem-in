#include "main.h"

void gui_pause()
{
	SDL_Event event;

	while (1)
	{
		SDL_WaitEvent(&event);
		if (event.key.keysym.sym == SDLK_SPACE && event.key.type == SDL_KEYUP)
			break ;
	}
}

void	gui_update(t_env *env)
{
	gui_update_map(env);
	gui_place_ants(env);
	SDL_Flip(env->sdl->screen);
	gui_pause();
}

void	gui_init(t_env *env)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	env->sdl->screen = SDL_SetVideoMode(WIN_W, WIN_H, 32, SDL_HWSURFACE);
	env->sdl->frame = 0;
	img_list(env->sdl);
}

void	gui_end()
{
	SDL_Quit();
}
