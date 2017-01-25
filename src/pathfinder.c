# include "main.h"

int		pf_setpaths(t_env *env, t_node *node)
{
	t_dlst_link	*link;
	int			h;

	h = -1;
	while (node)
	{
		if (node->type == N_END)
			return (1);
		dlst_push_back_c(env->closed, node, sizeof(t_node));
		if (node_chr_closed(env, node->parent->name))
		{
			link = node->next->link;
			while (link)
			{
				if (!node_chr_closed(env, ((t_node*)(link->content))->name)
					&& (((t_node*)(link->content))->h < h || h == -1))
					node->parent = ((t_node*)(link->content));
				link = link->next;
			}
		}
		node = node->parent;
	}
	return (0);
}

void	pf_setroutes(t_env *env, t_node *node, int i)
{
	t_dlst_link	*link;
	t_dlst_link	*check;
	t_node		*nn;

	dlst_push_back_c(env->closed, node, sizeof(t_node));
	link = node->next->link;
	while (link)
	{
		nn = ((t_node*)(link->content));
		if (nn->type == N_START)
			break ;
		if (nn->h == -1 || nn->h > i)
		{
			nn->h = i;
			nn->parent = node;
			if ((check = node_chr_closed(env, nn->name)))
			{
				check->content = NULL;
				dlst_erase(env->closed, check->index);
			}
		}
		link = link->next;
	}
	link = node->next->link;
	while (link)
	{
		nn = ((t_node*)(link->content));
		if (!node_chr_closed(env, nn->name))
			pf_setroutes(env, nn, i + 1);
		link = link->next;
	}
}

int		pathfinder(t_env *env)
{
	t_node		*start;
	t_dlst_link	*snext;
	int			path_to_end;

	env->closed = dlst_new();
	dlst_push_back_c(env->closed, node_chr_start(env), sizeof(t_node));
	pf_setroutes(env, node_chr_end(env), 1);
	start =  node_chr_start(env);
	snext = start->next->link;
	dlst_lclear(env->closed);
	dlst_init(env->closed);
	while (snext)
	{
		if (pf_setpaths(env, ((t_node*)(snext->content))))
			path_to_end = 1;
		snext = snext->next;
	}
	if (!path_to_end)
		return (lem_error(21));
	return (1);
}
