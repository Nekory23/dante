/*
** EPITECH PROJECT, 2020
** dante solver
** File description:
** init structs
*/

#include "solver.h"

void init_pile(pile_t **list, int x, int y)
{
    pile_t *temp = malloc(sizeof(pile_t));

    if (temp != NULL) {
        temp->x = x;
        temp->y = y;
        temp->prev = *list;
        *list = temp;
    }
}

void init_pos(pos_t *pos, list_t *list, int x, int y)
{
    pos_t *temp = malloc(sizeof(pos_t));

    temp->h = malloc(sizeof(pile_t));
    temp->h->prev = NULL;
    if (pos)
        temp->h = pos->h;
    else
        temp->h = NULL;
    temp->x = x;
    temp->y = y;
    temp->fx = x;
    temp->fy = y;
    temp->next = list->first;
    temp->prev = NULL;
    init_pile(&temp->h, x, y);
    if (list->first)
        list->first->prev = temp;
    else
        list->last = temp;
    list->first = temp;
}
