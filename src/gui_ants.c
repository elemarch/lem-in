#include "main.h"

#define AX aroom->coor.x
#define AY aroom->coor.y

void	gui_place_ants(t_env *env)
{
	int		i;
	t_node	*aroom;
	t_ant	ant;

	i = 0;
	while (i < env->ant_num)
	{
		ant = env->ant_tab[i];
		aroom = ant.actual;
		env->sdl->imgs[BMP_ANTS]->zone = img_defrect(32, 32, ant.index * 192, 0);
		img_put(env->sdl, BMP_ANTS, AX * WIN_G + 17, AY * WIN_G + 17);
		i++;
	}
}

//17 * 17
