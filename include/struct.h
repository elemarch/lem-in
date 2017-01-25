/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/01 15:00:00 by elemarch          #+#    #+#             */
/*   Updated: 2015/07/01 15:00:00 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
** === ENUMS ================================================================ **
*/

enum                e_type
{
	N_EMPTY = 0,
	N_START,
	N_END,
	N_ROOM,
	N_LINK
};

enum                e_state
{
	S_FREE = 0,
	S_FULL
};
/*
** === STRUCTURES =========================================================== **
*/

/*
** --- t_coor -------------------
**  simple coordinates structure.
** ------------------------------
*/

typedef struct      s_coor
{
	int             x;
	int             y;
}                   t_coor;

/*
** --- t_node -------------------
**  node structure for pathfinding algorithm.
** ------------------------------
**  type    : Node type. See e_type for values.
**  state   : Node state. See e_state for values.
**  h       : Node distance with end node.
**  parent  : Ptr to node's parent.
**  coor    : Node's coordinates. Equal to grid[x][y] values
** ------------------------------
*/

typedef struct      s_node
{
	char            *name;
	int             type;
	int             state;
	int             h;
	struct s_node   *parent;
	struct s_node   *child;
	t_coor          coor;
	t_dlst          *next;
}                   t_node;

/*
** --- t_ant --------------------
**  structure that contains an ant data.
** ------------------------------
**  target  : Ant's target node.
**  actual  : Ant's position node.
**  color   : 0 - 11 random value, give the ant a random sprite
** ------------------------------
*/

typedef struct      s_ant
{
	int             index;
	t_node          *target;
	t_node          *actual;
	int             color;
}                   t_ant;

/*
** --- t_env --------------------
**  environment variable
** ------------------------------
**  grid    : Two dimensional table that contains ptr to nodes.
**  nodes   : List of defined nodes.
**  r_end   : Ptr to end room node.
**  r_start : Ptr to start room node.
**  ant_tab : Table of all ants. First ant is 0 but displays 1.
**  max     : Maximum coordinates of the map
**  ant_num : Total number of ants.
**  ant_end : Total number of ants on END node.
**  sdl     : SDL variable
** ------------------------------
*/

typedef struct      s_env
{
	t_node          ***grid;
	t_dlst          *nodes;
	t_dlst          *closed;
	t_node          *r_end;
	t_node          *r_start;
	t_ant           *ant_tab;
	t_coor          max;
	t_coor          offset;
	int             ant_num;
	int             ant_end;
	t_sdl           *sdl;
	int             error;
}                   t_env;
#endif
