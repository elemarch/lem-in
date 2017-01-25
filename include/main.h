/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/09 15:00:00 by elemarch          #+#    #+#             */
/*   Updated: 2015/08/09 15:00:00 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

/*
** === INCLUDES ============================================================= **
*/

# include "libft.h"
# include "get_next_line.h"
# include "libdlst.h"
# include "/nfs/zfs-student-5/users/2014/elemarch/.brew/Cellar/sdl/1.2.15/include/SDL/SDL.h"
# include "gui.h"
# include "struct.h"
# include "fcntl.h"
# include <stdlib.h>
# include <stdio.h>

/*
** === PROTOTYPES =========================================================== **
*/

/*
** --- lemin_parse.c ------------
**  parsing functions
**  parsing stops when an arror is encountered and skip to pathfinding or a*
** ------------------------------
*/

int     parse(t_env *env);
t_node *crnode(t_env *env, t_coor c, char *name, int type);

/*
** --- node_chr.c ---------------
**  node research functions.
**  each except _closed returns a ptr to the corresponding node and NULL if
**      not found.
**  _closed returns a list link
** ------------------------------
*/

t_node      *node_chr_name(t_env *env, char *name);
t_dlst_link *node_chr_closed(t_env *env, char *name);
t_node      *node_chr_coor(t_env *env, t_coor c);
t_node      *node_chr_end(t_env *env);
t_node      *node_chr_start(t_env *env);

/*
** --- pathfinder.c -------------
**  my basic pathfinder algorithm - used without graphic
** ------------------------------
*/

int         pathfinder(t_env *env);

/*
** --- astar.c ------------------
**  implementation of A* pathfinding algorithm, used with graphics
**  it includes road crossing and link size - several ants can follow each
**      other in the same link.
** ------------------------------
*/

/*
** --- sim.c --------------------
**  ant simulation functions
** ------------------------------
*/

void        launch_sim(t_env *env);

/*
** --- lemin_error.c ------------
**  error list handle by this file:
**      1x - PARSE ERROR
**      10: ant number undefined
**      11: two rooms got same name
**      12: a link cannot be defined
**
**      2x - DATA ERROR
**      20: no end room
**      21: no path to end room
** ------------------------------
*/

int     lem_error(int n);

/*
** === GUI PROTOTYPES ======================================================= **
*/

/*
** --- gui_core.c ---------------
**  gui functions
** ------------------------------
*/

void        gui_pause();
void        gui_update(t_env *env);
void        gui_init(t_env *env);
void        gui_end();

/*
** --- gui_map.c ----------------
**  displays map
** ------------------------------
*/

void        gui_update_map(t_env *env);

/*
** --- gui_ants.c ---------------
**  displays ants
** ------------------------------
*/

void	gui_place_ants(t_env *env);

/*
** --- gui_img.c ----------------
**  img related functions
** ------------------------------
*/

SDL_Rect    *img_defrect(int h, int w, int x, int y);
void        img_put(t_sdl *sdl, int id, int x, int y);
void        img_load(t_sdl *sdl, int id, char *path, Uint32 trsp);
void        img_list(t_sdl *sdl);
void        img_putstr(t_sdl *sdl, char *str, int x, int y);

#endif
