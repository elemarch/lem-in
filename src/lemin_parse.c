#include "main.h"

t_node*		crnode(t_env *env, t_coor c, char *name, int type)
{
	t_node	*node;

	if (node_chr_name(env, name))
	{
		env->error = 11;
		return (NULL);
	}
	node = (t_node*)malloc(sizeof(t_node));
	node->coor.x = c.x;
	node->coor.y = c.y;
	if (c.x > env->max.x)
		env->max.x = c.x;
	if (c.y > env->max.y)
		env->max.y = c.y;
	node->name = ft_strdup(name);
	node->type = type;
	node->state = S_FREE;
	node->next = dlst_new();
	node->h = (node->type == N_ROOM ? -1 : 0);
	if (type == N_START && !node_chr_start(env))
		env->r_start = node;
	else if (type == N_END && !node_chr_end(env))
		env->r_end = node;
	dlst_push_back_c(env->nodes, node, sizeof(t_node));
	return (node);
}

void		crlink(t_env *env, char *nr1, char *nr2)
{
	t_node *n1;
	t_node *n2;

	n1 = node_chr_name(env, nr1);
	n2 = node_chr_name(env, nr2);
	if ((!n1 || !n2))
	{
		env->error = 12;
		return ;
	}
	dlst_push_back_c(n1->next, n2, sizeof(t_node));
	dlst_push_back_c(n2->next, n1, sizeof(t_node));
}

static int	parse_checkline(char **line)
{
	if ((!line || !line[0]))
		return (-1);
	if (!ft_strcmp(line[0], "##start"))
		return (N_START);
	if (!ft_strcmp(line[0], "##end"))
		return (N_END);
	if (line[0][0] == '#')
		return (4);
	if (!line[1] || !line[2])
		return (-1);
	return (N_ROOM);
}

int			parse(t_env *env)
{
	/*
	 * 1) first line is ant number
	 * 2) room list. format: string number number
	 * 3) link list. format: number-number
	*/
//	env->ant_num = 3;
//	env->nodes = dlst_new();
//	t_coor c;
//	c.x = 5;
//	c.y = 0;
//	crnode(env, c, "room A", N_ROOM);
//	if (!lem_error(env->error))
//		return (1);
//	c.x = 1;
//	c.y = 2;
//	crnode(env, c, "room START", N_START);
//	if (!lem_error(env->error))
//		return (1);
//	c.x = 9;
//	c.y = 2;
//	crnode(env, c, "room END", N_END);
//	if (!lem_error(env->error))
//		return (1);
//	c.x = 5;
//	c.y = 4;
//	crnode(env, c, "room B", N_ROOM);
//	if (!lem_error(env->error))
//		return (1);
//	crlink(env, "room START", "room A");
//	if (!lem_error(env->error))
//		return (1);
//	crlink(env, "room START", "room B");
//	if (!lem_error(env->error))
//		return (1);
//	crlink(env, "room A", "room END");
//	if (!lem_error(env->error))
//		return (1);
//	crlink(env, "room B", "room END");
//	if (!lem_error(env->error))
//		return (1);
//	crlink(env, "room A", "room B");
//	if (!lem_error(env->error))
//		return (1);
//	return (1);
	char	*line;
	char	**line_tab;
	t_coor	c;
	int		state;

	line = NULL;
	line_tab = NULL;
	state = N_ROOM;
	env->nodes = dlst_new();
	get_next_line(0, &line);
	env->ant_num = ft_atoi(line);
	if (!env->ant_num)
		return (lem_error(10));
	while (1)
	{
		if ((state = get_next_line(0, &line)) == -1 || 0)
			return (lem_error(13));
		ft_putstr(line);
		line_tab = ft_strsplit(line, ' ');
		state = parse_checkline(line_tab);
		ft_putstr(" -> ");
		ft_putnbr(state);
		ft_putchar('\n');
		if (state == -1)
			break ;
		if (state != N_ROOM)
			continue ;
		c.x = ft_atoi(line_tab[1]);
		c.y = ft_atoi(line_tab[2]);
		crnode(env, c, line_tab[0], state);
		state = N_ROOM;
		if (!lem_error(env->error))
			return (1);
	}
	if (state == -1)
	{
		line_tab = ft_strsplit(line, '-');
		if (!line_tab || !line_tab[0] || !line_tab[1])
		{
			return (1);
		}
		crlink(env, line_tab[0], line_tab[1]);
	}
	while (1)
	{
		if ((state = get_next_line(0, &line)) == -1 || state == 0)
			return (lem_error(13));
		ft_putstr("state : ");
		ft_putnbr(state);
		ft_putchar('\n');
		ft_putendl(line);
		line_tab = ft_strsplit(line, '-');
		if (line_tab && line_tab[0][0] == '#')
			continue ;
		if (!line_tab || !line_tab [0] || !line_tab[1])
			return (lem_error(13));
		crlink(env, line_tab[0], line_tab[1]);
		if (!lem_error(env->error))
			return (1);
	}
	return (1);
}
