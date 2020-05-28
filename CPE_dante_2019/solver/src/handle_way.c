/*
** EPITECH PROJECT, 2020
** dante solver
** File description:
** handle way
*/

#include "solver.h"

int get_dist_bis(int a, int b, pos_t **pos, map_t *m)
{
    if ((*pos)->prev)
        b = (m->y - 1) * (*pos)->prev->x + (m->x - 1) * (*pos)->prev->y;
    if (a < b)
        return (0);
    else if ((*pos)->prev && b > a)
        (*pos) = (*pos)->prev;
    return (0);
}

int get_dist(map_t *m, pos_t **pos, list_t *list)
{
    int a = 0;
    int b = 0;

    if ((*pos) == NULL)
        (*pos) = list->first;
    if ((*pos) == NULL)
        return (-1);
    a = (m->y - 1) * (*pos)->x + (m->x - 1) * (*pos)->y;
    get_dist_bis(a, b, pos, m);
    return (0);
}

void way_maker(pile_t *pile, map_t *m)
{
    pile_t *temp = pile;

    while (temp != NULL) {
        if (m->map[temp->x][temp->y])
            m->map[temp->x][temp->y] = 'o';
        temp = temp->prev;
    }
}
