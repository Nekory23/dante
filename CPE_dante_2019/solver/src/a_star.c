/*
** EPITECH PROJECT, 2020
** dante solver
** File description:
** a*
*/

#include "solver.h"

static int get_path(map_t *m, pos_t *pos, list_t *list)
{
    if (check_east(m, pos, list) == TRUE || check_west(m, pos, list) == TRUE)
        return (TRUE);
    if (check_north(m, pos, list) == TRUE || check_south(m, pos, list) == TRUE)
        return (TRUE);
    return (FALSE);
}

static pos_t *delete_pos(list_t *list, pos_t *pos)
{
    pos_t *temp = pos;
    pos_t *temp2 = pos;

    if (temp->prev)
        temp->prev->next = temp->next;
    else
        list->first = temp->next;
    if (temp->next)
        temp->next->prev = temp->prev;
    else
        list->last = temp->prev;
    temp = temp->next;
    free(temp2);
    return (temp);
}

static void a_star_bis(map_t *m, pos_t *pos)
{
    if (pos)
        m->map[pos->x][pos->y] = '2';
}

char **a_star(map_t *m, list_t *list, pos_t *pos)
{
    init_pos(pos, list, 0, 0);
    pos = list->first;
    m->map[pos->x][pos->y] = 'o';
    while (pos) {
        m->map[pos->x][pos->y] = '2';
        if (get_path(m, pos, list) == FALSE)
            pos = delete_pos(list, pos);
        if (pos && pos->x == (m->y - 1) && pos->y == (m->x - 1)) {
            way_maker(pos->h, m);
            return (m->map);
        }
        a_star_bis(m, pos);
        if (get_dist(m, &pos, list) == -1)
            return (NULL);
    }
    return (NULL);
}
