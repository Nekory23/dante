/*
** EPITECH PROJECT, 2020
** dante solver
** File description:
** split the map
*/

#include "solver.h"

static int count_lines(char *buff)
{
    int count = 0;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] == '\n')
            count++;
    return (count);
}

void split_map(map_t *m, char *buff)
{
    int temp = 0;
    int k = 0;

    m->y = count_lines(buff);
    m->map = malloc(sizeof(char *) * m->y);
    for (int j = 0; buff[temp] != '\0'; temp++) {
        if (buff[temp] == '\n')
            j++;
        m->map[j] = malloc(sizeof(char) * (temp + 1));
    }
    temp = 0;
    for (int j = 0; buff[temp] != '\0'; temp++, k++) {
        if (buff[temp] == '\n') {
            m->map[j][temp] = '\0';
            j++;
            temp++;
            k = 0;
        }
        m->map[j][k] = buff[temp];
    }
}
