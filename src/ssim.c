#include "main.h"

void	move_print(int i, char *r)
{
	ft_putchar('L');
	ft_putnbr(i);
	ft_putchar('-');
	ft_putstr(r);
	ft_putchar(' ');
}

t_node	*choose_path(t_env *env)
{
	t_dlst_link	*path;
	t_node		*node;


	path = env->r_start->next->link;
	while (path)
	{
		node = ((t_node*)(path->content));
		if (node->state == S_FREE)
			return (node);
		path = path->next;
	}
	return (env->r_start);
}

void	move_ant(t_env *env, t_ant *ant)
{
	if (ant->actual->type == N_END)
		return ;
	if (ant->actual->type == N_START)
		ant->target = choose_path(env);
	else
	{
		ant->target = ant->actual->parent;
		ant->actual->state = S_FREE;
	}
	ant->actual = ant->target;
	if (ant->actual->type == N_END)
	{
		move_print(ant->index, env->r_end->name);
		env->ant_end += 1;
		return ;
	}
	if (ant->actual->type != N_START)
	{
		move_print(ant->index, ant->actual->name);
		ant->actual->state = S_FULL;
	}
}

void	launch_sim(t_env *env)
{
	int		i;

	env->ant_tab = (t_ant*)malloc(sizeof(t_ant) * env->ant_num);
	i = 0;
	env->ant_end = 0;
	while (i < env->ant_num)
	{
		env->ant_tab[i].actual = env->r_start;
		env->ant_tab[i].color = rand() % 12;
		env->ant_tab[i].index = i + 1;
		i++;
	}
	gui_update(env);
	while (env->ant_end < env->ant_num)
	{
		i = 0;
		while (i < env->ant_num)
		{
			move_ant(env, &(env->ant_tab[i]));
			i++;
		}
		gui_update(env);
		ft_putstr("\n");
	}
}
