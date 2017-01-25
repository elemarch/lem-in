# include "main.h"

# define NODE ((t_node*)link->content)

t_node		*node_chr_name(t_env *env, char *name)
{
	t_dlst_link	*link;
	t_node		*node;

	link = env->nodes->link;
	while (link && (ft_strcmp(NODE->name, name)))
		link = link->next;
	if (link)
		node = (t_node*)link->content;
	else
		return (NULL);
	return (node);
}

t_node		*node_chr_coor(t_env *env, t_coor c)
{
	t_dlst_link	*link;
	t_node		*node;

	link = env->nodes->link;
	while (link && (NODE->coor.x != c.x || NODE->coor.y != c.y))
		link = link->next;
	if (link)
		node = (t_node*)link->content;
	else
		return (NULL);
	return (node);
}

t_node		*node_chr_end(t_env *env)
{
	t_dlst_link	*link;
	t_node		*node;

	link = env->nodes->link;
	while (link && NODE->type != N_END)
		link = link->next;
	if (link)
		node = (t_node*)link->content;
	else
		return (NULL);
	return (node);
}

t_node		*node_chr_start(t_env *env)
{
	t_dlst_link	*link;
	t_node		*node;

	link = env->nodes->link;
	while (link && NODE->type != N_START)
		link = link->next;
	if (link)
		node = (t_node*)link->content;
	else
		return (NULL);
	return (node);
}

t_dlst_link	*node_chr_closed(t_env *env, char *name)
{
	t_dlst_link	*link;

	link = env->closed->link;
	while (link)
	{
		if (!ft_strcmp(name, ((t_node*)(link->content))->name))
			return (link);
		link = link->next;
	}
	return (NULL);
}
