/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/23 09:05:27 by elemarch          #+#    #+#             */
/*   Updated: 2015/09/23 09:05:29 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "main.h"

void    node_disp(t_node *node)
{
	t_dlst_link *link;
	link = node->next->link;

	printf("node coord: (%d, %d)\n", node->coor.x, node->coor.y);
	printf("node name: '%s'\n", node->name);
	printf("node state: %d\n", node->state);
	printf("node hval: %d\n", node->h);
	printf("node nexts: ");
	while (link)
	{
		printf("%s - ", ((t_node*)link->content)->name);
		link = link->next;
	}
	printf("\n\n");
}

void    route_disp(t_node *start)
{
	t_dlst_link *link = start->next->link;
	t_node      *cur;
	while (link)
	{
		printf("START");
		cur = ((t_node*)(link->content));
		while (cur)
		{
			printf("->%s", cur->name);
			cur = cur->parent;
		}
		printf("\n");
		link = link->next;
	}
}

int     main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_env   env;
	env.error = 0;
	env.offset.x = 0;
	env.max.x = 0;
	env.max.y = 0;
	env.offset.y = 0;
	env.error = 0;
	//char  *line;
	//change it to match different map. dont forget errors too ;)
	ft_putendl("parse");
	parse(&env);
//	t_dlst_link *lnk;
//	lnk = env.nodes->link;
//	while (lnk)
//	{
//		node_disp((t_node*)(lnk->content));
//		lnk = lnk->next;
//	}
	// if '+', launch astar, else pathfinder
	ft_putendl("pathfinder");
	if (!pathfinder(&env))
		return (lem_error(1));
	ft_putendl("gui init");
	gui_init(&env);
	ft_putendl("simulation");
	launch_sim(&env);
	//astar_core(env);
	ft_putendl("end");
	gui_end();
	return (0);
}
