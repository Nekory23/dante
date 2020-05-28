/*
** EPITECH PROJECT, 2020
** dante
** File description:
** generator
*/

#include "generator.h"

void generate_imperfect(map_t *m)
{
    maze_perfect(m);
    for (int i = 0; i != m->y - 1; i++)
        printf("%s\n", m->map[i]);
    printf("%s", m->map[m->y- 1]);
}

void generate_perfect(map_t *m)
{
    maze_perfect(m);
    for (int i = 0; i != m->y - 1; i++)
        printf("%s\n", m->map[i]);
    printf("%s", m->map[m->y - 1]);
}

void generate(map_t *m)
{
    if (m->perfect)
        generate_perfect(m);
    else
        generate_imperfect(m);
}
