/*
** EPITECH PROJECT, 2020
** dante
** File description:
** fill_struct
*/

#include "generator.h"

void fill_struct(map_t *m, int ac, char **av)
{
    if (ac == 3)
        m->perfect = FALSE;
    else
        m->perfect = TRUE;
    m->x = atoi(av[1]);
    m->y = atoi(av[2]);
    m->map = malloc(sizeof(char *) * m->y);
    for (int i = 0; i != m->y; i++)
        m->map[i] = malloc(sizeof(char) * m->x);
    for (int i = 0; i != m->y; i++) {
        for (int j = 0; j != m->x; j++)
            m->map[i][j] = 'X';
        m->map[i][m->x] = '\0';
    }
}
