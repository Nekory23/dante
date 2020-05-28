/*
** EPITECH PROJECT, 2020
** dante
** File description:
** solver.h
*/

#ifndef __SOLVER_H__
#define __SOLVER_H__

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct pile_s
{
    int x;
    int y;
    struct pile_s *prev;
} pile_t;

typedef struct pos_s
{
    int x;
    int y;
    int fx;
    int fy;
    pile_t *h;
    struct pos_s *next;
    struct pos_s *prev;
} pos_t;

typedef struct list_s
{
    pos_t *first;
    pos_t *last;
} list_t;

typedef struct map_s
{
    int x;
    int y;
    char **map;
} map_t;

int get_dist(map_t *m, pos_t **pos, list_t *list);
void way_maker(pile_t *pile, map_t *m);

int check_east(map_t *m, pos_t *pos, list_t *list);
int check_west(map_t *m, pos_t *pos, list_t *list);
int check_north(map_t *m, pos_t *pos, list_t *list);
int check_south(map_t *m, pos_t *pos, list_t *list);

int solve_this(map_t *m);
char **a_star(map_t *m, list_t *list, pos_t *pos);
void init_pos(pos_t *pos, list_t *list, int x, int y);
void init_pile(pile_t **list, int x, int y);

void fill_struct(map_t *m);
void split_map(map_t *m, char *buff);

int error_handling(char *arg,  map_t *m);
void write_error(char *str);
int my_strlen(char const *str);

#define ERROR 84
#define SUCCESS 0
#define TRUE 1
#define FALSE 0

#define STR_ERROR_ARG "this program must take 2 args. it must be a maze file.\n"
#define STR_ERROR_OPEN "could not open file.\n"
#define STR_ERROR_READ "could not read from file.\n"
#define STR_ERROR_INV "the maze is invalid.\n"

#endif
