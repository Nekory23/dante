/*
** EPITECH PROJECT, 2020
** generation
** File description:
** maze_perfect
*/

#include "generator.h"

static void open_map(map_t *m)
{
    for (int i = 0; i < m->y - 1; i += 2)
        for (int j = 0; j != m->x; j++)
            m->map[i][j] = '*';
    if (m->perfect == 1)
        for (int i = 1; i < m->y - 1; i += 2)
            m->map[i][rand() % m->x] = '*';
    else
        for (int i = 1; i < m->y - 1; i += 2) {
            m->map[i][rand() % m->x] = '*';
            m->map[i][rand() % m->x] = '*';
        }
    if (m->y % 2 == 0)
        m->map[m->y - 1][m->x - 1] = '*';
}

void maze_perfect(map_t *m)
{
    if (m->y % 2 == 1)
        for (int j = 0; j != m->x; j++)
            m->map[m->y - 1][j] = '*';
    open_map(m);
}
