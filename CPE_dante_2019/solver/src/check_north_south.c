/*
** EPITECH PROJECT, 2020
** dante solver
** File description:
** check if we can move north
*/

#include "solver.h"

int check_south(map_t *m, pos_t *pos, list_t *list)
{
    if ((pos->x - 1 != -1) && m->map[pos->x - 1][pos->y] == '*') {
        if (((pos->x + 1) != m->y) && m->map[pos->x + 1][pos->y] == '*') {
            init_pos(pos, list, pos->x + 1, pos->y);
            m->map[pos->x][pos->y] = '2';
        }
        if ((pos->y + 1 != m->x) && m->map[pos->x][pos->y + 1] == '*') {
            init_pos(pos, list, pos->x, pos->y + 1);
            m->map[pos->x][pos->y] = '2';
        }
        if ((pos->y - 1 != - 1) && m->map[pos->x][pos->y - 1] == '*') {
            init_pos(pos, list, pos->x, pos->y - 1);
            m->map[pos->x][pos->y] = '2';
        }
        pos->x -= 1;
        init_pile(&pos->h, pos->x, pos->y);
        return (TRUE);
    }
    return (FALSE);
}

int check_north(map_t *m, pos_t *pos, list_t *list)
{
    if ((pos->x + 1 != m->y) && m->map[pos->x + 1][pos->y] == '*') {
        if (((pos->y + 1) != m->x) && m->map[pos->x][pos->y + 1] == '*') {
            init_pos(pos, list, pos->x, pos->y + 1);
            m->map[pos->x][pos->y] = '2';
        }
        if ((pos->y - 1 != -1) && m->map[pos->x][pos->y - 1] == '*') {
            init_pos(pos, list, pos->x, pos->y - 1);
            m->map[pos->x][pos->y] = '2';
        }
        if ((pos->x - 1 != - 1) && m->map[pos->x - 1][pos->y] == '*') {
            init_pos(pos, list, pos->x - 1, pos->y);
            m->map[pos->x][pos->y] = '2';
        }
        pos->x += 1;
        init_pile(&pos->h, pos->x, pos->y);
        return (TRUE);
    }
    return (FALSE);
}
