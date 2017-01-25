#include "main.h"
//void    node_disp(t_node *node)
//{
//	t_dlst_link *link;
//	link = node->next->link;

//	printf("node coord: (%d, %d)\n", node->coor.x, node->coor.y);
//	printf("node name: '%s'\n", node->name);
//	printf("node state: %d\n", node->state);
//	printf("node hval: %d\n", node->h);
//	printf("node nexts: ");
//	while (link)
//	{
//		printf("%s - ", ((t_node*)link->content)->name);
//		link = link->next;
//	}
//	printf("\n\n");
//}

# define NX n->coor.x
# define NY n->coor.y

void		gui_update_map(t_env *env)
{
	t_coor		c;
	t_dlst_link	*link;
	t_node		*n;

	c.x = 0;
	c.y = 0;
	while (c.x <= WIN_W - WIN_G)
	{
		c.y = 0;
		while (c.y <= WIN_H - WIN_G)
		{
			img_put(env->sdl, BMP_NEMPTY, c.x, c.y);
			c.y += WIN_G;
		}
		c.x += WIN_G;
	}
	link = env->nodes->link;
	while (link)
	{
		n = ((t_node*)(link->content));
		if (n->type == N_START)
			img_put(env->sdl, BMP_NSTART, NX * WIN_G, NY * WIN_G);
		else if (n->type == N_END)
			img_put(env->sdl, BMP_NEND, NX * WIN_G, NY * WIN_G);
		else
			img_put(env->sdl, BMP_NROOM, NX * WIN_G, NY * WIN_G);
		link = link->next;
	}
//	gui_map_links(env);
}
