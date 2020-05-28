/*
** EPITECH PROJECT, 2020
** dante solver
** File description:
** solver
*/

#include "solver.h"

static int entrance_or_exit_occupied(map_t *m)
{
    if (m->map[0][0] == 'X' || m->map[m->y - 1][m->x - 1] == 'X') {
        printf("no solution found\n");
        return (TRUE);
    }
    return (FALSE);
}

static void init_list(list_t *list)
{
    list->first = NULL;
    list->last = NULL;
}

static void replace_twos(map_t *m)
{
    for (int i = 0; i != m->y; i++)
        for (int j = 0; j != m->x; j++)
            if (m->map[i][j] == '2')
                m->map[i][j] = '*';
}

int solve_this(map_t *m)
{
    list_t list;

    if (entrance_or_exit_occupied(m))
        return (TRUE);
    init_list(&list);
    m->map = a_star(m, &list, NULL);
    if (m->map == NULL)
        printf("no solution found\n");
    else {
        replace_twos(m);
        for (int i = 0; i != m->y - 1; i++)
            printf("%s\n", m->map[i]);
        printf("%s", m->map[m->y - 1]);
    }
    return (TRUE);
}
